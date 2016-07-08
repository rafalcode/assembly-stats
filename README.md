assembly-stats
==============

Get assembly statistics from FASTA and FASTQ files.

RF fork: it would be nice to also read gzipped fasta and fastq files, slowly introducing some changes.

Installation
------------

Run the following commands to install the program
`assembly-stats` to `/usr/local/bin/`.

    mkdir build
    cd build
    cmake ..
    make
    make test
    make install

If you do not have root access, you can install to a directory of your choice
by changing the call to cmake. For example:

    cmake -DINSTALL_DIR:PATH=/foo/bar/ ..

would mean you finish up with a copy of `assembly-stats` in the directory
`/foo/bar/`.

Usage
-----

Get statistics from a list of files:

    assembly-stats file.fasta another_file.fastq

Detection of FASTA or FASTQ format of each file is automatic from the file
contents, so file names and extensions are irrelevant.

The default output format is human readable.
You can change the output format and ignore sequences shorter than a
given length. Get the full usage by running with no files listed:

    $ assembly-stats
    usage: stats [options] <list of fasta/q files>
    
    Reports sequence length statistics from fasta and/or fastq files
    
    options:
    -l <int>
        Minimum length cutoff for each sequence.
        Sequences shorter than the cutoff will be ignored [1]
    -s
        Print 'grep friendly' output
    -t
        Print tab-delimited output
    -u
        Print tab-delimited output with no header line

Example
-------

Here is an example on the _Plasmodium falciparum_ reference genome:

    $ assembly-stats Pf3D7_v3.fasta
    stats for Pf3D7_v3.fasta
    sum = 23328019, n = 16, ave = 1458001.19, largest = 3291936
    N50 = 1687656, n = 5
    N60 = 1472805, n = 7
    N70 = 1445207, n = 8
    N80 = 1343557, n = 10
    N90 = 1067971, n = 12
    N100 = 5967, n = 16
    N_count = 0
    Gaps = 0

The numbers should be self-explanatory, except maybe lines like
`N50 = 1687656, n = 5`. The N50 is 1687656, with 50% of the assembly in 5
sequences. A "gap" is any run of Ns of any length (it is case-insensitive so
counts any "n" as well).
