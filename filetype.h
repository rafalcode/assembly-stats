#ifndef FILETYPE
#define FILETYPE

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

const short FASTA_FILE = 1;
const short FASTQ_FILE = 2;
const short UNKNOWN = 3;
const short FASTAGZ_FILE = 4;
const short FASTQGZ_FILE = 5;

short fastaOrFastq(string filename);

#endif // FILETYPE
