#include <iostream>
#include <cstring>
#include "lab8.h"
using namespace std;

/* Task 0: calculate and set the priority for one person

    1. Priority associated with different job types
        1. Use M represent Medical staffs, they have highest priority of 3
        2. Use S represent Service workers, they have a priority value of 2
        3. Use O represent Other people, they have a priority value of 1
    2. Priority value with ages
        1. age >= 60 priority is 4
        2. age < 60 and age >= 40 priority is 3
        3. age < 40 and age >= 20 priority is 2
        4. age < 20 priority value is 1
    
    A person's priority = job priority + age priority
    For exmaple, a medical staff with age >=60 has priority 3 + 4 = 7
*/
void setPriority(Person& p){
	char job = p.job;
	int age = p.age;
	int k = 0;
	if (job == 'M') {
		k += 3;
	}else if(job == 'S'){
		k += 2;
	}
	else if (job == 'O') {
		k += 1;
	}
	if (age >= 60) {
		k += 4;
	}
	else if (age >= 40) {
		k += 3;
	}
	else if (age >= 20) {
		k += 2;
	}
	else {
		k += 1;
	}
	p.priority=k;
}

/*
    Task 1. Sort the sign up queue via pointers and print the priority queue
    1a. Set the priority of everyone in the sign up queue 
    1b. Figure out the vaccine sequence by properly set up the pointer
    1c. Print the priority queue

    queue is the sign up queue, struct array
    pointerqueue is the priority queue, a pointer array pointing to elements of queue
    when do sorting, sign up queue remain unchanged!!! 
    the sorting is done by setup pointer array. 
    For example, pointerqueue[0] now points to the person with highest priority. 
*/
void prioritySort( Person queue[], Person* pointerqueue[], int size) {
    Person* pointerA;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!queue[i].vaccined) 
            pointerqueue[count++]=&queue[i];
    } 
    for (int i = 0; i < count-1; i++){
        // Last i elements are already in place
        for (int j = 0; j < count-i-1; j++){
            if (pointerqueue[j]->priority < pointerqueue[j+1]->priority) {
                pointerA=pointerqueue[j];
                pointerqueue[j]=pointerqueue[j+1];
                pointerqueue[j+1]=pointerA;
            }
        }
    }
}

/* 
    Task 2. Assume that the the highest priority person is vaccinated 
    Remove him from the priority queue and print the updated priority queue
    Important: 
    DO NOT remove him from the sign up queue
*/
void vaccinateTopPriority(Person queue[], Person* pointerqueue[], int size) {
    prioritySort(queue, pointerqueue, size);
    pointerqueue[0]->vaccined = true;
    prioritySort(queue, pointerqueue, size);
}

/* 
    Task 3. Add a new person to the END of current sign up queue 
            Since the newly-added person can cut in line with his priority,
            most likely you need to update the priority queue 

    This function is used when setup the initial queues from file
*/
void addPerson(int id, const char name[], char job, int age, Person queue[], Person* pointerqueue[], int& size) {
    queue[size].job=job;
    queue[size].age=age;
    queue[size].id=id;
    queue[size].vaccined=0;
    strcpy(queue[size].name, name);
    setPriority(queue[size]);
    prioritySort(queue, pointerqueue, size+1);
}
