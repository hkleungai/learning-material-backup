sub codon2aa{
my($codon)=@_;
$codon= uc $codon;
my(%genetic_code) = (
'TCA'=>'S', #Serine
'TCC'=>'S', #Serine
'TCG'=>'S',  #Serine
'TCT'=>'S', #Serine
 'TTC'=>'F', #Phenylalanine

  'TTT'=>'F', #Phenylalanine

    'TTA'=>'L', #Leucine

     'TTG'=>'L', #Leucine

    'TAC'=>'Y', #Tyrosine

    'TAT'=>'Y', #Tyrosine
     'TAA'=>'_', #Stop

   'TAG'=>'_', #Stop

    'TGC'=>'C', #Cysteine

   'TGT'=>'C', #Cysteine

   'TGA'=>'_', #Stop

     'TGG'=>'W', #Tryptophan

     'CTA'=>'L', #Leucine

     'CTC'=>'L', #Leucine

     'CTG'=>'L', #Leucine

     'CTT'=>'L', #Leucine

   'CCA'=>'P', #Proline

     'CAT'=>'H', #Histidine

     'CAA'=>'Q', #Glutamine

     'CAG'=>'Q', #Glutamine

     'CGA'=>'R', #Arginine

     'CGC'=>'R', #Arginine

    'CGG'=>'R', #Arginine

     'CGT'=>'R', #Arginine

     'ATA'=>'T', #Isoleucine

     'ATC'=>'T', #Isoleucine

     'ATT'=>'T', #Isoleucine

     'ATG'=>'M', #Methionine

     'ACA'=>'T', #Threonine

     'ACC'=>'T', #Threonine

     'ACG'=>'T', #Threonine

    'ACT'=>'T', #Threonine

     'AAC'=>'N', #Asparagine

     'AAT'=>'N', #Asparagine

     'AAA'=>'K', #Lysine

     'AAG'=>'K', #Lysine

     'AGC'=>'S', #Serine#Valine

    'AGT'=>'S', #Serine

    'AGA'=>'R', #Arginine

    'AGG'=>'R', #Arginine

   'CCC'=>'P', #Proline

    'CCG'=>'P', #Proline

     'CCT'=>'P', #Proline

     'CAC'=>'H', #Histidine

     'GTA'=>'V', #Valine

     'GTC'=>'V', #Valine

    'GTG'=>'V', #Valine

     'GTT'=>'V', #Valine

    'GCA'=>'A', #Alanine

     'GCC'=>'A', #Alanine

     'GCG'=>'A', #Alanine

     'GCT'=>'A', #Alanine

    'GAC'=>'D', #Aspartic Acid

    'GAT'=>'D', #Aspartic Acid

    'GAA'=>'E', #Glutamic Acid

     'GAG'=>'E', #Glutamic Acid

     'GGA'=>'G', #Glycine

     'GGC'=>'G', #Glycine

     'GGG'=>'G', #Glycine

     'GGT'=>'G', #Glycine

     );

 

     if(exists $genetic_code{$codon}){

     return $genetic_code{$codon};

    }

     else{

     print  "Bad Codon\"$codon\"!!\n";

     exit;

     }

    }

 

print "Please choose one of the following for entring the DNA sequence\n";
print "Press 1 for manual entry or 2 for file\n";
 

$entry=<STDIN>;
chomp($entry);
if($entry==1){
print "enter the sequence:-\n";
$dna=<STDIN>;
chomp($dna);
}elsif($entry==2){
print "enter the filename(if it is in another folder please specify the path)\n";
$dnafile=<STDIN>;
open(FILE,$dnafile);
@filecontents=<FILE>;
close FILE;
chomp(@filecontents);
$dna=join('',@filecontents);
}else{
print "please press only 1 or 2\n";
exit;
}
 

#my $dna="TCATTCTCATTC";
my $protein='';
my $codon3;
for(my $i=0; $i<(length($dna)-2); $i+=3){
$codon3=substr($dna,$i,3);
 

$protein.=  codon2aa($codon3);
}
 

print "\nThe protein is:-\n$protein\n";
$len = length($protein);
print "The length of the protein is:-\n$len\n";