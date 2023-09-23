/*
Silvana Dorita Ruiz Olivarría A01252346
Alan Jose Muñoz Ramirez A01252054
Actividad 3.2 Programando un DFA
Descripción del programa: 
Hacer un programa que reciba como entrada un archivo de texto que contenga 
expresiones aritméticas y comentarios, y nos regrese una tabla con cada uno 
de sus tokens encontrados, en el orden en que fueron encontrados e indicando 
de qué tipo son.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // std::find and remove
#include <string>
using namespace std;

// Global variable
int index = 0;

class Lexer{
    private:
        
        char symbolArr[4] = {'+', '*', '/', '^'};
        string symbolArrName[4] = {"Suma", "Multiplicacion", "Division", "Potencia"};
        char negPrevChar[7] = {'*', '/', '^', 'E', 'e', '(', '='};
        vector <string> operacion;
        vector <string> nombreOper;

    public:
        
        void readFile(string archivo);
        
        void lexerAritmetico(string archivo);

        void identifier(string line);
        
        void isVariable(string line);

        void isNegative(string line);

        void isNumberPositive(string line);

        void isSymbol(string line);

        void isSubstraction(string line);

        void isOpenParenthesis(string line);

        void isCloseParenthesis(string line);
        
        void isEqualSign(string line);

        void isComment(string line);

        string isWhiteSpace(string line);

        void isCommentSpace(string line);

};


string Lexer::isWhiteSpace(string line){
    int posComment = -1;
    for(int i = 0; i < line.size(); i++){
        if(line[i] == '/'){
            if(line[i + 1] == '/'){
                posComment = i;
                break;
            }
        }
    } 
    if(posComment == -1){
        
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end()); // To remove spaces from line.
    } else {
      
        //line.erase(remove_if(line.begin(), line.begin()+posComment-1, ::isblank), line.begin()+posComment-1); // To remove spaces from line.
        string line2 = line.substr(0,posComment);
        string comm = line.substr(posComment);
        
        line2.erase(remove_if(line2.begin(), line2.end(), ::isspace), line2.end());
        line = line2 + comm;
        cout << "line con lo de comment " << line << endl;
    }
    return line;
    
}


void Lexer::readFile(string archivo){
    string myChar;
    ifstream myFile(archivo);
    string line;
    if(myFile.is_open()){
        while(getline(myFile, line)){
            // Función de análisis de tokens
            index = 0;
            cout << line << endl;
            line = isWhiteSpace(line);
            cout << "LINEA------------- " << line <<endl;
           
            identifier(line);
        }  
        myFile.close(); 
    }
    
}


void Lexer::isVariable(string line){
    string variable = "";
    bool flagVar = false;
    bool cond = true;
    while(cond){
        cout << "index var: " << index << endl;
        if(isalpha(line[index])){
            variable += line[index];
            flagVar = true;
            cout << "if " << index << endl;
            index++;
        } else if((isdigit(line[index]) || line[index] == '_') && flagVar == true ){
            variable += line[index]; 
            cout << "else if " << index << endl;
            index++;
        } else {
            cond = false;
            cout << "else " << index << endl;
            break;
        } 
    }
    if(!variable.empty()){
        operacion.push_back(variable);
        nombreOper.push_back("Variable");
    }
    flagVar = false;
    variable = "";
    return;
}

void Lexer::isNegative(string line){
    bool flagNeg = false;
    string negString = "";
    bool flagVar = false;
    bool exponBool = false;
    bool realBool = false;
    bool digitBool = false;
    bool cond = true;

    while(cond){
        if(line[index] == '-'){
            if(index == 0) { // If it is the first character of the expression, store it on num.
                negString += line[index];
             
                flagNeg = true;
                cout << "index 0 en neg " << index << endl;
                index++;
                cout << "------------" << endl;
                cout << "numneg " << negString << endl;
                
            } else if( auto it = find(negPrevChar, negPrevChar+7, line[index-1])){ // If '-' is after any of the symbols in negPrevChar,then it is a negative number and not a substraction

                if(it != negPrevChar+7 ){
                    negString += line[index];
                    
                    flagNeg = true;
                    cout << "desp de opeardor neg" << " : " << index << endl;
                   
                    index++; 
                
                } else {
                    isSubstraction(line);
                    return;
                }
            } 
        } 
        //Negative numbers
        else if((isdigit(line[index])) && flagNeg){
            negString += line[index];
            digitBool = true;
            cout << "soy un digito en neg " << index <<endl; 
            index++;
            cout << "------------" << endl;
            cout << "numneg " << negString << endl;
        } else if (line[index] == '.' && flagNeg && digitBool){
            negString += line[index];
            realBool = true;
            index++;
        } else if(flagNeg && digitBool && (line[index] == 'E' || line[index] == 'e')){
            negString += line[index];
            exponBool = true;
            index++;
        } else if(flagNeg && digitBool && exponBool && line[index] == '-'){
            negString += line[index];
            index++;
        } 
        
        // Negative variable

        else if(isalpha(line[index]) && flagNeg){
            negString += line[index];
            flagVar = true;
            cout << "NEG VARIABLE " << negString << endl;
            cout << "if para alpha de neg " << index << endl;
            index++;
        } else if((isdigit(line[index]) || line[index] == '_') && flagVar && flagNeg){
            negString += line[index]; 
            cout << "else if " << index << endl;
            index++;
        }

        else {
            cond = false;
            cout << "sali del num neg en: " << index << endl;
            break;
        }
    }

    if(!negString.empty()){
        operacion.push_back(negString);
    }

    if(realBool){
        nombreOper.push_back("Real");
    } else if(flagVar){
        nombreOper.push_back("Variable");
    } else if(!negString.empty()) {
        nombreOper.push_back("Entero");
    }

    flagNeg = false;
    flagVar = false;
    negString = "";
    
    return;
}



void Lexer::isSubstraction(string line) {
    cout << "en is substraction" << endl;
    bool cond = true;
    while(cond){
        if(line[index] == '-'){
         
            if(index == 0) { // If it is the first character of the expression, store it on num.
                isNegative(line);
                
            } else if( auto it = find(negPrevChar, negPrevChar+7, line[index-1])){ // If '-' is after any of the symbols in negPrevChar,then it is a negative number and not a substraction
                if(it != negPrevChar+7 ){
                    isNegative(line);
                } else {
                    operacion.push_back(to_string(line[index])); // insertarlo en un vector
                    nombreOper.push_back("Resta");
                    index++;
                }    
            }
        } else {
            cond = false; 
            break;  
        }
    }
}



void Lexer::isNumberPositive(string line){
    string numPos = "";
    bool cond = true;
    bool numPosBool = false;
    bool exponBool = false;
    bool realBool = false;
    while(cond){
        if(isdigit(line[index])){
            numPos += line[index];
            numPosBool = true;
            index++;
        } else if (numPosBool && line[index] == '.' ){
            numPos += line[index];
            realBool = true;
            index++;
        } else if(numPosBool && (line[index] == 'E' || line[index] == 'e')){
            numPos += line[index];
            exponBool = true;
            index++;
        } else if(numPosBool && exponBool && line[index] == '-'){
            numPos += line[index];
            index++;
        } else {
            cond = false;
            break;
        }
    }
    if(!numPos.empty()){
        operacion.push_back(numPos);
    }
    if(realBool){
        nombreOper.push_back("Real");
    } else if (!numPos.empty() ){
        nombreOper.push_back("Entero");
    }

    numPos = "";
    return;
}

void Lexer::isComment(string line){
    string comment = "";
    string iniComment = "//";
    bool flagCom = false;
    bool cond = true;
    while(cond && index <= line.size() - 1){ 
        cout << "func comment " << index << endl;  
        if(line[index] == '/'){
            cout << "primer if de / " << index << endl; 
            index++;
            if(line[index] == '/'){
                comment += "//"; 
                cout << "COMENTARIO " << comment << endl;
                flagCom = true;
                index++;
            } else if (!flagCom){
                index--;
                comment = "";
                cond = false;
            }
            
        }else if(flagCom){
            cout << "else if /" << endl;
            comment += line[index]; 
            index++;
        } else {
            cond = false;
            comment = "";
            return;
        }
    }
    if(!comment.empty()){
        operacion.push_back(comment);
        nombreOper.push_back("Comentario");
    }

    flagCom = false;
    comment = "";
    return;
    
}



void Lexer::isSymbol(string line){
    cout << "index symbol: " << index << endl;
    bool cond = true;
    while(cond){
        auto it = find(symbolArr, symbolArr+4, line[index]); //Serchs line[index] including symbolArr and excluding symbolArr+6
        if(it != symbolArr+4 && line[index + 1] != '/'){
            cout << "entre al symbol ARRRRRR" << endl;
            operacion.push_back(to_string(line[index]));
            cout << "*it: " << *it << endl;
            for(int i = 0; i < sizeof(symbolArr)/sizeof(symbolArr[0]); i++){
                if(*it == symbolArr[i]){ // *it es el elemento de symbolArr que es el operador en la expresión
                    nombreOper.push_back(symbolArrName[i]);
                    cout << "Symbol arr name:::::::: " << symbolArrName[i] << endl;
                }
            }
            index++;
            cout << "salida symbol: " << index << endl;
        
        } else { 
            cout << "entre al symbol elseeeeeeeeeeeeeeeee" << endl;
            cond = false;
            break; 
        }
    }
    
}




void Lexer::isOpenParenthesis(string line){
    bool cond = true;
    while(cond){
        if(line[index] == '('){
            operacion.push_back(to_string(line[index])); // insertarlo en un vector
            nombreOper.push_back("Paréntesis que abre");
            index++;
        } else {
            cond = false; 
            break;  
        }
    }
}



void Lexer::isCloseParenthesis(string line){
    bool cond = true;
    while(cond){   
        if(line[index] == ')'){
            operacion.push_back(to_string(line[index])); // insertarlo en un vector
            nombreOper.push_back("Paréntesis que cierra");
            index++;
        } else {
            cond = false;
            break;
        }
        
    }
}



void Lexer::isEqualSign(string line){
    bool cond = true;
    while(cond){
        if(line[index] == '='){
            operacion.push_back(to_string(line[index])); // insertarlo en un vector
            nombreOper.push_back("Asignación");
            index++;
        } else {
            cond = false;
            break; 
        }
        
    }
    
}

void Lexer::isCommentSpace(string line){
    bool cond = true;
    while(cond){
        if(line[index] == ' '){
            index++;
        } else {
            cond = false;
            break; 
        }
    }
}


void Lexer::lexerAritmetico(string archivo){
    cout << "Index" << "\t" <<  "Token" << "\t" << "Tipo" << endl;
    for(int i = 0; i < operacion.size(); i++){
        cout << i  <<  "\t " << operacion[i] << "\t" << nombreOper[i] <<endl;
    }



    cout << "-------------------------------------------" << endl;
    for(int i = 0; i < nombreOper.size(); i++){
        cout << nombreOper[i] <<endl;
    }
    return;
}


void Lexer::identifier(string line){
  
    while(index <= line.size() -1){

        if(index <= line.size() - 1){
            isComment(line);
        } else {
            break;
        }
        
        if(index <= line.size() - 1){
            isVariable(line);
        } else {
            break;
        }
         
        if(index <= line.size() - 1){
            isNegative(line);
        } else {
            break;
        }
        
        if(index <= line.size() - 1){
            isNumberPositive(line);
        } else {
            break;
        }
        
        if(index <= line.size() - 1){
            isSymbol(line);
        } else {
            break;
        } 
    
        if(index <= line.size() - 1){
            isSubstraction(line);
        } else {
            break;
        }
        
       if(index <= line.size() - 1){
            isOpenParenthesis(line);
        } else {
            break;
        } 

        if(index <= line.size() - 1){
            isCloseParenthesis(line);
        } else {
            break;
        } 

        if(index <= line.size() - 1){
            isEqualSign(line);
        } else {
            break;
        }
        
        if(index <= line.size() - 1){
            isCommentSpace(line);
        } else {
            break;
        } 
    }
    return;
}



int main() {
    Lexer objLex;
    string archivo;
    cout << "Ingrese el nombre del archivo a leer: " << endl;
    cin >> archivo;
    objLex.readFile(archivo);
    objLex.lexerAritmetico(archivo);
    
    return 0;
}
