/*
    COMP3511 Spring 2022 
    PA2: Simplified Linux Completely Fair Scheduler (CFS)

    Your name:
    Your ITSC email:           @connect.ust.hk 

    Declaration:

    I declare that I am not involved in plagiarism
    I understand that both parties (i.e., students providing the codes and students copying the codes) will receive 0 marks. 

*/

// Note: Necessary header files are included
// Do not add extra header files
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define MAX_PROCESS
// For simplicity, assume that we have at most 10 processes
#define MAX_PROCESS 10

// Assume that we only need to support 2 types of space characters: 
// " " (space), "\t" (tab)
#define SPACE_CHARS " \t"

// Keywords (to be used when parsing the input)
#define KEYWORD_NUM_PROCESS "num_process"
#define KEYWORD_SCHED_LATENCY "sched_latency"
#define KEYWORD_MIN_GRANULARITY "min_granularity"
#define KEYWORD_BURST_TIME "burst_time"
#define KEYWORD_NICE_VALUE "nice_value"


// Useful string template used in printf()
// We will use diff program to auto-grade 
// Please use the following templates in printf to avoid formatting errors
//
// Examples:
//   printf(template_cfs_algorithm)  # print === CFS algorithm ===\n on the screen
//   printf(template_step_i, 0)      # print === Step 0 ===\n on the screen

const char template_key_value_pair[] = "%s = %d\n";
const char template_parsed_values[] = "=== CFS input values ===\n";
const char template_cfs_algorithm[] = "=== CFS algorithm ===\n";
const char template_step_i[] = "=== Step %d ===\n";
const char template_gantt_chart[] = "=== Gantt chart ===\n";



// The lookup table for the mapping of nice value to the weight value
static const int DEFAULT_WEIGHT = 1024;
static const int NICE_TO_WEIGHT[40] = {
    88761, 71755, 56483, 46273, 36291, // nice: -20 to -16
    29154, 23254, 18705, 14949, 11916, // nice: -15 to -11
     9548,  7620,  6100,  4904,  3906, // nice: -10 to  -6
     3121,  2501,  1991,  1586,  1277, // nice:  -5 to  -1
     1024,   820,   655,   526,   423, // nice:   0 to   4
      335,   272,   215,   172,   137, // nice:   5 to   9
      110,    87,    70,    56,    45, // nice:  10 to  14
       36,    29,    23,    18,    15, // nice:  15 to  19
};

// Helper function: look up the weight value based on the given nice value
// Valid nice value: -20 to 19 (inclusive)
int nice_to_weight(int nice) {
    if (nice < -20 || nice > 19)
        perror("Error: wrong nice_to_weight value");
    return NICE_TO_WEIGHT[nice+20];
}

// struct CFSProcess - a data structure for the CFS scheduling
struct CFSProcess {
    int weight; // the weight value, lookup based on the nice value
    double vruntime; // each process needs to store its vruntime
    int remain_time; // initially, it is equal to the burst_time. This value keeps decreasing until 0
    int time_slice; // to be calculated based on the input values at the beginning of the CFS scheduling
};

// Constant and data structure for Gantt chart dispaly
#define MAX_GANTT_CHART 300
struct GanttChartItem {
    int pid;
    int duration;
};

// Global variables:
// For simplicity, let's make everything static without any dyanmic memory allocation
// In other words, we don't need to use malloc()/free() 
// It will save you lots of time to debug if everything is static
int num_process = 0; 
int sched_latency = 0;
int min_granularity = 0;
int burst_time[MAX_PROCESS] = {0};
int nice_value[MAX_PROCESS] = {0};
struct CFSProcess process[MAX_PROCESS];
struct GanttChartItem chart[MAX_GANTT_CHART];
int num_chart_item = 0;
int finish_process_count = 0; // the number of finished process 

// Helper function: print the Gantt chart
void gantt_chart_print() {
    int t=0, i=0, id=0;
    printf(template_gantt_chart);
    printf("%d ", t);
    for (i=0; i<num_chart_item; i++) {
        t = t + chart[i].duration;
        printf("P%d %d ", chart[i].pid, t);
    }
    printf("\n");
}

// Helper function: append an item to the Gantt chart
void gantt_chart_append_item(int pid, int duration) {
    int i = num_chart_item;
    chart[i].pid = pid;
    chart[i].duration = duration;
    num_chart_item = i+1;
}

// Helper function: Check whether the line is a blank line (for input parsing)
int is_blank(char *line) {
    char *ch = line;
    while ( *ch != '\0' ) {
        if ( !isspace(*ch) )
            return 0;
        ch++;
    }
    return 1;
}
// Helper function: Check whether the input line should be skipped (for input parsing)
int is_skip(char *line) {
    if ( is_blank(line) )
        return 1;
    char *ch = line ;
    while ( *ch != '\0' ) {
        if ( !isspace(*ch) && *ch == '#')
            return 1;
        ch++;
    }
    return 0;
}

// Helper function: print an array of integer
void print_vec(char *name, int vec[MAX_PROCESS], int n) {
    int i;
    printf("%s = [", name);
    for (i=0;i<n;i++) {
        printf("%d", vec[i]);
        if ( i<n-1 )
            printf(",");
    }
    printf("]\n");
}

// Helper: print the parsed values on the console
void print_parsed_values() {
    printf(template_parsed_values);
    printf(template_key_value_pair, KEYWORD_NUM_PROCESS, num_process);
    printf(template_key_value_pair, KEYWORD_SCHED_LATENCY, sched_latency);
    printf(template_key_value_pair, KEYWORD_MIN_GRANULARITY, min_granularity);
    print_vec(KEYWORD_BURST_TIME, burst_time, num_process);
    print_vec(KEYWORD_NICE_VALUE, nice_value, num_process);
}

// Helper: calculate the per-process time slice
int calculate_per_process_time_slice(
    int weight,            // weight of a process
    int sched_latency,     // the scheduler latency
    int sum_of_weight      // total sum of weights
    ) {
    return (int)((double) weight * sched_latency / sum_of_weight);
}

// Helper: calculate the new per-process vruntime
double calculate_new_vruntime(
    double vruntime, // the old vruntime
    double runtime, // how much time the process run
    double weight //  weight of a process
    ) {
    return vruntime + (double) DEFAULT_WEIGHT / weight * runtime;
}

// Helper: The tokenize function
// Note: Unlike PA1, we won't add the NULL item because 
// we won't use it with execvp
void parse_tokens(char **argv, char *line, int *numTokens, char *delimiter) {
    int argc = 0;
    char *token = strtok(line, delimiter);
    while (token != NULL)
    {
        argv[argc++] = token;
        token = strtok(NULL, delimiter);
    }
    *numTokens = argc;
}

// Helper: print the CFS processes in a table 
void print_cfs_process() {
    int i;
    printf("Process\tWeight\tRemain\tSlice\tvruntime\n");
    for (i=0;i<num_process;i++)
        printf("P%d\t%d\t%d\t%d\t%.2f\n", 
            i,
            process[i].weight,
            process[i].remain_time,
            process[i].time_slice,
            process[i].vruntime
            );
}

// Helper: The input parsing is given
// You don't need to implement the input parsing in PA2
void parse_input() {
    FILE *fp = stdin;
    char *line = NULL;
    ssize_t nread;
    size_t len = 0;

    char *two_tokens[2]; // buffer for 2 tokens
    char *process_tokens[MAX_PROCESS]; // buffer for n tokens
    int numTokens = 0, n=0, i=0;
    char equal_plus_spaces_delimiters[5] = "";

    strcpy(equal_plus_spaces_delimiters, "=");
    strcat(equal_plus_spaces_delimiters,SPACE_CHARS);

    while ( (nread = getline(&line, &len, fp)) != -1 ) {
        if ( is_skip(line) == 0)  {
            line = strtok(line,"\n");

            if (strstr(line, KEYWORD_NUM_PROCESS)) {
                // parse num_process
                parse_tokens(two_tokens, line, &numTokens, equal_plus_spaces_delimiters);
                if (numTokens == 2) {
                    sscanf(two_tokens[1], "%d", &num_process);
                }
            } else if (strstr(line, KEYWORD_SCHED_LATENCY)) {
                // parse sched_latency
                parse_tokens(two_tokens, line, &numTokens, equal_plus_spaces_delimiters);
                if (numTokens == 2) {
                    sscanf(two_tokens[1], "%d", &sched_latency);
                }
            } else if (strstr(line, KEYWORD_MIN_GRANULARITY)) {
                // parse min_granularity
                parse_tokens(two_tokens, line, &numTokens, equal_plus_spaces_delimiters);
                if (numTokens == 2) {
                    sscanf(two_tokens[1], "%d", &min_granularity);
                }
            } else if (strstr(line, KEYWORD_BURST_TIME)) {

                // parse the burst_time 
                // note: we parse the equal delimiter first
                parse_tokens(two_tokens, line, &numTokens, "=");
                if (numTokens == 2) {
                    // parse the second part using SPACE_CHARS
                    parse_tokens(process_tokens, two_tokens[1], &n, SPACE_CHARS);
                    for  (i=0; i<n; i++) {
                        sscanf(process_tokens[i], "%d", &burst_time[i]);
                    }
                }
            } else if (strstr(line, KEYWORD_NICE_VALUE)) {
                // parse the nice_value
                // note: we parse the equal delimiter first
                parse_tokens(two_tokens, line, &numTokens, "=");
                if (numTokens == 2) {
                    // parse the second part using SPACE_CHARS
                    parse_tokens(process_tokens, two_tokens[1], &n, SPACE_CHARS);
                    for (i=0; i<n; i++) {
                        sscanf(process_tokens[i], "%d", &nice_value[i]);
                    }
                }
            }

        }
        
    }
}

// TODO: initialize the array of CFSProcess
void init_cfs_process() {
    
    
}

// TODO: Implement the simplified CFS here
void run_cfs_scheduling() {
    int step = 0;
    printf(template_cfs_algorithm);
    printf(template_step_i, step++);
    print_cfs_process();
    finish_process_count = 0;


}

int main() {
    parse_input();          // parse the input  
    print_parsed_values();  // print the parsed input values
    init_cfs_process();     // initialize the processes
    run_cfs_scheduling();   // run the simplified CFS
    gantt_chart_print();    // display the final Gantt chart
    return 0;
}