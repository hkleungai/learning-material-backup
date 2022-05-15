//Source: Chau Ming Kit
//Date: 6/10/2000

#include <fstream.h>
#include <ctype.h>

#define MAX_CHAR 1024
#define MAX_LINE 1024

int strToUpper(char* line);

int main(int argc, char* argv[])
{
	if (argc != 2) {
		cerr << "Invalid argument number\n";
		return -1;
	}

	int ch;	
	int stat[26];

	//file open
	//fstream file;		/*alternative*/
	//file.open(argv[1], ios::in);
	ifstream file(argv[1]);
	if ( !file ) {
		cerr << "unable to open input file: " << argv[1] << endl;
		return -2;
	}

	//data init
	for(int i=0; i<26; i++) {
		stat[i] = 0;
	}

	//character count
	//while ( (ch = file.get()) && (ch != EOF) ) {	/* alternative*/
	while ((ch = file.get()) != EOF) {
		cout.put(ch);	//echo everything to the terminal
		ch = tolower(ch) - (int)'a';
		if ( (ch >= 0) && (ch < 26) )
			stat[ch]++;
	}
	cout << "\nStatistics:\n";
	for(int i=0; i<26; i++) {
		cout << (char)( i+(int)'a' ) << ": " << stat[i] << "\t";
		if (i%5 == 4) cout << endl;
	}
	cout << endl;


	//line echo
	char buf[MAX_CHAR];
	char* lines[MAX_LINE];
	int count = 0;

	file.clear();		// clear the state flag
	file.seekg(0);		// set get pointer back to first charater
	while ( file.getline(buf, MAX_CHAR) ) {
		lines[count] = new char[strlen(buf) + 1];
		strcpy(lines[count], buf);
		strToUpper(lines[count]);
		count++;
	}

	cout << "\nNumber of line: " << count << endl;
	for(int i=0; i<count; i++) {
		cout << i << ": " << lines[i] << endl;
	}
	file.close();
	return 0;
}

int strToUpper(char* line)
{
	char* ptr;
	int i;

	ptr = line;
	for(i=0; i<strlen(line); i++) {
		*ptr = toupper(*ptr);
		ptr++;
	}
	return 0;
}
