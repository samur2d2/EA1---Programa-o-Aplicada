#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
using namespace std;

void FirstWindow(){
    for (int i=0; i<30; i++){cout<<endl;}
    char option = ' ';
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t +-----------------------------------------+" << endl;
    cout << "\t |                                         |" << endl;
    cout << "\t |    TO EXPERIENCE BETTER PERFORMANCE     |" << endl;
    cout << "\t |     I RECOMMEND USING CODE BLOCKS       |" << endl;
    cout << "\t |                                         |" << endl;
    cout << "\t |                                         |" << endl;
    cout << "\t |    commands like system(cls) may not    |" << endl;
    cout << "\t |        work correctly elsewhere         |" << endl;
    cout << "\t |                                         |" << endl;
    cout << "\t |                                         |" << endl;
    cout << "\t +-----------------------------------------+" << endl;
    cout << "\t |                 Samuel Ribeiro - 04/21  |" << endl;
    cout << "\t +-----------------------------------------+" << endl;
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t Please enter Y to continue or N to exit: ";
    cin >> option;
    if (toupper(option) == 'Y'){
        cout << "OPA";
    }else{exit(EXIT_FAILURE);}

}
//-----------------------------------------------------------------------------------------------------------------
int SecWindow(){
    for (int i=0; i<30; i++){cout<<endl;}
    int option = 0;
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t +-------------------------------------+" << endl;
    cout << "\t |                                     |" << endl;
    cout << "\t |       BEFORE WE CONTINUE...         |" << endl;
    cout << "\t |     PLEASE SELECT AN OPTION:        |" << endl;
    cout << "\t |                                     |" << endl;
    cout << "\t +-------------------------------------+" << endl;
    cout << "\t |                                     |" << endl;
    cout << "\t |   1 to using codeblocks             |" << endl;
    cout << "\t |   2 to using another app/site       |" << endl;
    cout << "\t |                                     |" << endl;
    cout << "\t +-------------------------------------+" << endl;
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t Please enter your answer: ";
    cin >> option;
    return(option);
}
//-----------------------------------------------------------------------------------------------------------------
string NumberToString(char character=' '){
    switch(character){
    case '0': return("A");
        break;
    case '1': return("B");
        break;
    case '2': return("C");
        break;
    case '3': return("D");
        break;
    case '4': return("E");
        break;
    case '5': return("F");
        break;
    case '6': return("G");
        break;
    case '7': return("H");
        break;
    case '8': return("I");
        break;
    case '9': return("J");
        break;
    }
}
//-----------------------------------------------------------------------------------------------------------------
string LetterToNumber(char character=' '){
    switch(character){
    case 'A': return("0");
        break;
    case 'B': return("1");
        break;
    case 'C': return("2");
        break;
    case 'D': return("3");
        break;
    case 'E': return("4");
        break;
    case 'F': return("5");
        break;
    case 'G': return("6");
        break;
    case 'H': return("7");
        break;
    case 'I': return("8");
        break;
    case 'J': return("9");
        break;
    }
}
//-----------------------------------------------------------------------------------------------------------------
int StringToNumber(char character=' '){
    switch(character){
    case '0': return(0);
        break;
    case '1': return(1);
        break;
    case '2': return(2);
        break;
    case '3': return(3);
        break;
    case '4': return(4);
        break;
    case '5': return(5);
        break;
    case '6': return(6);
        break;
    case '7': return(7);
        break;
    case '8': return(8);
        break;
    case '9': return(9);
        break;
    }
}
//-----------------------------------------------------------------------------------------------------------------
string FirstEncode(string code, int i){
    string to_return = " ";
    if ((code[i] >= 48) && (code[i] <=57)){ //TO NUMBER;
        to_return += "Z";
        to_return += NumberToString(code[i]); //CONVERT THE NUMBER INTO ITS RESPECTIVE LETTER;
    }else if ((code[i] >= 65) && (code[i] <= 89)){ //TO LETTERS
        to_return += code[i];
    }else if (code[i] == 90){ //Z
        to_return += "ZZ";
    }
    to_return.erase(0,1); //EXCLUDES THE FIRST CHAR - A USELLES SPACE
    return(to_return);
}
//-----------------------------------------------------------------------------------------------------------------
bool error = false; //USED TO CODES WITH SOME KIND OF ERROR;
string FirstDecode(string code, int i){
    string to_return = " ";
    if ((code[i] >= 65) && (code[i] <= 89)){ //IF IS A LETTER;
        if ((i > 0) && (code[i-1] >= 48) && (code[i-1] <=57)){ //IF IT'S A NUMBER BEFORE IT;
            for (int j=0; j<StringToNumber(code[i-1]); j++){ //IT'LL REPEAT THE LETTER N TIMES;
                to_return += code[i];
            }
        }else if (code[i-1] == 90){} //IF IT'S A Z BEFORE THE LETTER THEN IT WILL BE IGNORED;
        else{
            to_return += code[i]; //JUST REPEAR THE LETTER;
        }
    }else if (code[i] == 90){ //IF IT'S A Z;
        if ((i > 0) && (code[i-1] >= 48) && (code[i-1] <=57)){ //IF IT'S A NUMBER BEFORE THE Z;
            int constant = StringToNumber(code[i-1]); //IT WILL TRANSFORM THE STRING NUMBER INTO AN INTERGER;
            for (int j=0; j<(constant/2); j++){ //EVERY TWO Z, ONE MUST BE WRITTEN;
                to_return += code[i];
            }
            if (constant % 2 != 0){ //IF IT IS AN ODD NUMBER OF Z I KNOW THAT ONE OF THEY BELONGS TO THE NEXT LETTER;
                to_return += LetterToNumber(code[i+1]); //CONVERT THE LETTERS INTO NUMBERS;
            }
        }else if ((code[i+1] >= 65) && (code[i+1] <= 89)){ //IF IT'S A LETTER AFTER THE Z;
            to_return += LetterToNumber(code[i+1]);
        }else if (code[i+1] == 90){ //IF THERE ARE TWO Z IN SEQUENCE THEN ITS AN ERROR;
            error = true;
        }
    }
    to_return.erase(0,1); //EXCLUDES THE FIRST CHAR - A USELLES SPACE;
    return(to_return);
}
//-----------------------------------------------------------------------------------------------------------------
void Replit(){ //AN UGLY VERSION TO RUN IN THE STUPID REPLIT;
    char type=' ';
    string code="", st_new_code="", nd_new_code="";
    while ((type != 'C') && (type != 'D')){ //WHILE THE ANSWER IS DIFFERENT FROM C OR D;
        cout << "Enter C or D: "; cin >> type;
        type = toupper(type);
    }
    fflush(stdin);
    cout << "Enter the code in CAPS: "; cin >> code; //GONNA READ THE CODE;
    if (code.length() > 999){ //IT'LL LIMIT THE CODE UNTIL 1000 CHARACTERES;
        code.erase(999); //DELETE EVERYTHING AFTER 1000;
    }

    for (int i=0; i<code.length(); i++){
        code[i] = toupper(code[i]); //JUST PUTTINH EVERY LETTER IN UPCASE;
    }

    if (type == 'C'){ //IF YOU CHOOSE THE ENCODER MODE;
        for (int i=0; i<code.length(); i++){
            st_new_code += FirstEncode(code, i); //HERE IS THE FIRST PART OF THE CODIFICATION;
        }

        /* A cadeia resultante desta primeira etapa é recodificada para eliminar repetições de caracteres.
        O procedimento consiste em uma variação da compressão RLE, assim:
        PELO QUE DEU PRA ENTENDER PESQUISANDO SOBRE RLE, DEVO COMPRIMIR APENAS AS LETRAS REPETIDAS EM SEQUENCIA
        EXEMPLO: AAABCDAAAA -> 3ABCD4A  */

        int cont=1;
        for (int i=1; i<st_new_code.length()+1; i++){
            while (st_new_code[i] == st_new_code[i-1]){ //IF THE LETTER IS REPEATING IN SEQUENCE;
                cont++; //IT WILL COUNT HOW MANY LETTER IS REPEATED
                i++;
            }
            if (cont > 1){ //IF THERE IS MORE THAN 1 LETTER IN SEQUENCE;
                nd_new_code += to_string(cont) + st_new_code[i-1];
            }else{
                nd_new_code += st_new_code[i-1]; //IF ONLY ONE LETTER WITHOUT REPEATING IN SEQUENCE
            }
            cont = 1;
        }
        cout << st_new_code << endl; //SHOW THE RESULTS;
        cout << nd_new_code << endl; //SHOW THE RESULTS;

    }else{ //DECODER MODE;
        for (int i=0; i<code.length(); i++){
            st_new_code += FirstDecode(code, i); //HERE IS THE FIRST PART OF THE DECODIFICATION;
        }
        if (error == true){
            st_new_code = " "; //IF SOME ERROR OCCURRED, THEN THE OUTPUT IT'S GONNA BE NOTHING;
        }
        cout << st_new_code << endl; //SHOW THE RESULTS;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void Codeblocks(){
    system("cls");
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t +----------------------------------------------+" << endl;
    cout << "\t |                                              |" << endl;
    cout << "\t |            IMPORTANT INFORMATIONS            |" << endl;
    cout << "\t |                                              |" << endl;
    cout << "\t +----------------------------------------------+" << endl;
    cout << "\t |                                              |" << endl;
    cout << "\t |   - Enter C to encode the string             |" << endl;
    cout << "\t |   - Enter D to decode the string             |" << endl;
    cout << "\t |   - Enter the string to be processed         |" << endl;
    cout << "\t |   - The string must be less than 1K char     |" << endl;
    cout << "\t |   - Any char after 1K will be disregarded    |" << endl;
    cout << "\t |                                              |" << endl;
    cout << "\t +----------------------------------------------+" << endl;
    for (int i=0; i<1; i++){cout << endl;}
    cout << "\t" << system("pause");

    char type=' ';
    string code="", st_new_code="", nd_new_code="";

    system("cls");
    while ((type != 'C') && (type != 'D')){
        for (int i=0; i<3; i++){cout << endl;}
        cout << "\t +-------------------------------------+" << endl;
        cout << "\t |                                     |" << endl;
        cout << "\t |      ENTER C OR D TO CONTINUE       |" << endl;
        cout << "\t |                                     |" << endl;
        cout << "\t +-------------------------------------+" << endl;
        for (int i=0; i<1; i++){cout << endl;}
        cout << "\t Answer: "; cin >> type;
        type = toupper(type);
    }
    fflush(stdin);
    system("cls");
    for (int i=0; i<3; i++){cout << endl;}
    cout << "\t +-------------------------------------+" << endl;
    cout << "\t |                                     |" << endl;
    cout << "\t |     ENTER THE CODE IN CAPSLOCK      |" << endl;
    cout << "\t |                                     |" << endl;
    cout << "\t +-------------------------------------+" << endl;
    cout << "\t |                     max: 1000 char  |" << endl;
    cout << "\t +-------------------------------------+" << endl;
        for (int i=0; i<1; i++){cout << endl;}
    cout << "\t Code: "; cin >> code;
    if (code.length() > 999){
        code.erase(999);
    }
    for (int i=0; i<code.length(); i++){
            code[i] = toupper(code[i]);
    }
    if (type == 'C'){ //ENCODER MODE;
        for (int i=0; i<code.length(); i++){
            st_new_code += FirstEncode(code, i);
        }

        /* A cadeia resultante desta primeira etapa é recodificada para eliminar repetições de caracteres.
        O procedimento consiste em uma variação da compressão RLE, assim:
        PELO QUE DEU PRA ENTENDER PESQUISANDO SOBRE RLE, DEVO COMPRIMIR APENAS AS LETRAS REPETIDAS EM SEQUENCIA
        EXEMPLO: AAABCDAAAA -> 3ABCD4A  */

        int cont=1;
        for (int i=1; i<st_new_code.length()+1; i++){
            while (st_new_code[i] == st_new_code[i-1]){
                cont++;
                i++;
            }
            if (cont > 1){
                nd_new_code += to_string(cont) + st_new_code[i-1];
            }else{
                nd_new_code += st_new_code[i-1];
            }
            cont = 1;
        }
        system("cls");
        for (int i=0; i<3; i++){cout << endl;}
        cout << "\t +----------------------------------------------------------------" << endl;
        cout << "\t |                                                                " << endl;
        cout << "\t |  Original Code: " << code << endl;
        cout << "\t |                                                                " << endl;
        cout << "\t +----------------------------------------------------------------" << endl;
        cout << "\t |                                                                " << endl;
        cout << "\t |   First Decode: " << st_new_code << endl;
        cout << "\t |                                                                " << endl;
        cout << "\t +----------------------------------------------------------------" << endl;
        cout << "\t |                                                                " << endl;
        cout << "\t |   Final Decode: " << nd_new_code << endl;
        cout << "\t |                                                                " << endl;
        cout << "\t +----------------------------------------------------------------" << endl;
        for (int i=0; i<3; i++){cout << endl;}

    }else{ //DECODER MODE;
        for (int i=0; i<code.length(); i++){
            st_new_code += FirstDecode(code, i);
            nd_new_code = st_new_code;
        }
        if (error == true){
            st_new_code = " ";
            nd_new_code = st_new_code;
        }
        system("cls");
        for (int i=0; i<3; i++){cout << endl;}
        cout << "\t +----------------------------------------------------------------" << endl;
        cout << "\t |                                                                " << endl;
        cout << "\t |  Original Code: " << code << endl;
        cout << "\t |                                                                " << endl;
        cout << "\t +----------------------------------------------------------------" << endl;
        cout << "\t |                                                                " << endl;
        cout << "\t |   First Decode: " << st_new_code << endl;
        cout << "\t |                                                                " << endl;
        cout << "\t +----------------------------------------------------------------" << endl;
        cout << "\t |                                                                " << endl;
        cout << "\t |   Final Decode: " << nd_new_code << endl;
        cout << "\t |                                                                " << endl;
        cout << "\t +----------------------------------------------------------------" << endl;
        for (int i=0; i<3; i++){cout << endl;}
    }
}
//-----------------------------------------------------------------------------------------------------------------
int main(){

    FirstWindow();

    int app_used = SecWindow();
    switch(app_used){
    case 1:
        Codeblocks();
        break;
    case 2:
        Replit();
        break;
    default:
        break;
    }
}
