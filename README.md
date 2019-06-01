# opperations-on-DNA-
program that helps biologists manage and analyze their sequence
data while storing it in a computer. The biological data can be divided into 3 types of sequences:
DNA, RNA, and Protein. A DNA sequence can be of type (promoter, motif, tail,
noncoding). Each DNA sequence consists of 2 strands, each strand is a string that is formed by
the following 4 characters (nucleotides): A,C,G,T and each strand has its own direction (like 2-way
street). ACAAGG, CGATACAG, TTACGCCAT, and GACCCCTA are examples of single DNA strands.
The second DNA strand is the reversed complement of the first strand. For example, the following
are 2 connected DNA strands:
A strand is read in direction from 5’ to 3’. The second strand can be easily built from the first strand
as follows:
1) Convert each T to A, each A to T, each C to G, and each G to C, then
2) Reverse the overall string (to be correctly read from 5’ to 3’).
A DNA sequence can be converted to RNA sequence which is then converted to a Protein
sequence. RNA results from one DNA strand. To convert a DNA strand to an RNA sequence,
replace each T by U. So, the RNA sequences corresponding to the past DNA examples are
ACAAGG, CGAUACAG, UUACGCCAU, and GACCCCUA respectively. RNA sequence can be of type
(mRNA, tRNA, rRNA).
Finally, The RNA sequence can be converted into a Protein sequence. Each 3 characters of the
RNA sequence, called a codon, can be converted/mapped into one Protein character (called
AminoAcid). The mapping of codons into AminoAcids is shown in the following Table or Wheel.
So, the RNA sequence ACGUACGUAUAA is converted into the Protein sequence TYV. The last
codon UAA is not converted into an AminoAcid because it is a stop codon. Proteins come in
different types (Hormon, Enzyme, TF, Cellular_Function).
