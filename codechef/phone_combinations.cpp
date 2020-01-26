string letters[10] = {"","","abc","def","ghi,"jkl","mno","pqrs","tuv","wxyz"};

void printwords(int num){
    int digits[10];
    int i=0;
    while(num){
        digits[i++]=num%10;
        num/=10;
    }
    i--;
    string word;
    for(int j=0;j<letters[digits[i]];j++){
        word[j]=letters[digits[i]][j];
        printwords(num,)
    }
}