# Programando un DFA
## Autómatas
### ¿Qué debo de instalar?
Para ejecutar los archivos .jff donde se tienen a los autómatas se debe instalar el programa
JFLAP7.1.jar (https://www.jflap.org/). 
### ¿Cómo correr el programa?
Una vez instalado se debe abrir el programa y seleccionar la opción “File” en el menú superior.
Después dar click en “Open” y seleccionar el archivo deseado.  

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/25034218-9016-4e31-9c72-8e0f9c1e187a)

Para probar cadenas en los autómatas es necesario dar click en la opción de “Input” y posteriormente
en “Multiple Run”. 
![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/ab2cef5e-98c1-4d3f-b8b3-41c1a728a80e)

Después, se mostrará esta ventana donde es posible ingresar cadenas de input y verificar si estas son
aceptadas o no. 
![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/20fc100d-d4c8-4458-972e-77b63a3e8be1)

## Autómata general:
En este caso, para ingresar una expresión al autómata es necesario ingresar variables con letras
mayúsculas y minúsculas, guion bajo y dígitos como “a”, números reales o enteros como “b”, los
operadores “+, -, /, ^ , * como “c”, la asignación como “=”, paréntesis de apertura como “(”, paréntesis
de cierre como “)”, comentarios como “//” y el fin de una expresión como “\n”. Por lo que, si se busca
ingresar la expresión myvar+hello se debe ingresar aca\n. 

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/61eb1605-4156-4d49-bdc2-5063f3525bca)

En el caso del autómata de “a”: 
- la transición “Letra” es cualquier letra minúscula o mayúscula de “a” a “z”. 
- la transición “Dígito” es un número de 0 a 9. 
- la transición “Underscore” es “_”. 
- la transición “Negativo” es “-”. 

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/2030be8c-a9bf-47d0-a9fd-a869aa422795)


En el caso del autómata “b”: 
- la transición “Dígito” es un número de 0 a 9. 
- la transición “Exponencial” es “E” o “e”. 
- la transición “Negativo” es “-”. 

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/933f3835-3c52-437b-9cf5-3ce83162796e)

### ¿Qué se obtiene de salida? 
Para que una cadena sea aceptada, debe cumplir con que la ruta de estados que sigue con las
transiciones en el autómata lleve a un estado final, así se mostrará la palabra “Accept” como
resultado. En cambio, si la cadena lleva a un estado no final, el resultado será “Reject”. 

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/19747c32-16f3-442c-a73a-1c22e23174b3)

## Autómata general 
### Ejemplos de cadenas aceptadas: 
- La primera expresión consiste de una variable, operador y un número. 
  - En el autómata se representa como: acb\n. 
  - Un ejemplo de la expresión puede ser: myVar+3.4\n.  
- La segunda expresión es como la anterior pero fue extendida. 
  - En el autómata se representa como: acbcb\n. 
  - Un ejemplo de la expresión puede ser: num+3/6.2\n. 
- La tercera expresión está encerrada con paréntesis. 
  - En el autómata se representa como: (acb)\n. 
  - Un ejemplo de la expresión puede ser: (num1+9)\n. 
- La cuarta expresión se encuentra encerrada entre paréntesis como la anterior pero extendida. 
  - En el autómata se representa como: (acbca)\n. 
  - Un ejemplo de la expresión puede ser: (num1+9-num2)\n. 
- La quinta expresión contiene paréntesis seguidos. 
  - En el autómata se representa como: (bca)c(aca)\n. 
  - Un ejemplo de la expresión puede ser: (3.14+num_1)*(num2+num3)\n. 
- La sexta expresión contiene una expresión después un operador y luego una expresión entre
paréntesis. 
  - En el autómata se representa como: bcbc(aca)\n. 
  - Un ejemplo de la expresión puede ser: 10.2-3*(num_1^num5)\n. 
- La séptima expresión muestra una asignación después de un número o variable. 
  - En el autómata se representa como: a=acb\n. 
  - Un ejemplo de la expresión puede ser: var=num1/4.1\n 
- La octava expresión muestra una asignación después de número o variable y seguido, una
expresión entre paréntesis. 
  - En el autómata se representa como: a=(bca)\n. 
  - Un ejemplo de la expresión puede ser: carros=(30*llantas)\n 
- La novena expresión muestra una asignación después de número o variable y seguido, un
número o variable y un operador a un lado de una expresión entre paréntesis. 
  - En el autómata se representa como: a=bc(aca)\n. 
  - Un ejemplo de la expresión puede ser: num1=30.2*(num3^num4)\n. 
- La décima expresión cuenta con números y/o variables y operadores antes de una asignación. 
  - En el autómata se representa como: bca=a\n. 
  - Un ejemplo de la expresión puede ser: 12.3*num1=contador\n 
- La onceava expresión contiene paréntesis y después una asignación. 
  - En el autómata se representa como: (aca)=b\n. 
  - Un ejemplo de la expresión puede ser: (var1^var2)=435\n 
- La doceava expresión es un comentario. 
  - En el autómata se representa como: //aca\n. 
  - Un ejemplo de la expresión puede ser: //var_1*var_2\n. 
- La expresión número trece es una expresión aritmética seguida de un comentario. 
  - En el autómata se representa como: acb//bcb\n. 
  - Un ejemplo de la expresión puede ser: myvar-3//45+3\n.

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/a01fb902-648f-45cc-8c57-c3b57696f134)

### Ejemplos de cadenas rechazadas: 
- La primera expresión rechazada es cuando se comienza con un caracter inválido como un
operador, cierre de paréntesis o asignación. 
  - En el autómata se representa como: cacb\n. 
  - Un ejemplo de la expresión puede ser: *var/45\n. 
- La segunda expresión rechazada consiste en repetir algún caracter como asignación u
operador. 
  - En el autómata se representa como: accb\n. 
  - Un ejemplo de la expresión puede ser: my_Var++8E99\n. 
- La tercera expresión rechazada consiste en escribir una variable y después un número, o
viceversa. Es decir, sin algo para separarlos como un operador o asignación. 
  - En el autómata se representa como: baca\n. 
  - Un ejemplo de la expresión puede ser: 46myVar+myNum\n. 
- La cuarta expresión rechazada contiene un paréntesis de apertura pero no uno de cierre. 
  - En el autómata se representa como: (bcb\n. 
  - Un ejemplo de la expresión puede ser: (46E8-5.5\n.

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/f31595d4-808e-4435-af12-663f94ab4b79)

## Autómata “a”: Variables 
### Ejemplos de cadenas aceptadas: 
- La primera expresión consiste de una variable que empieza con una letra y está formada
solamente por letras. 
  - En el autómata se representa como: LetraLetraLetraLetraLetra. 
  - Un ejemplo de la expresión puede ser: myVar. 
- La segunda expresión consiste de una variable que empieza con una letra, es seguida por
varias letras y termina con dos dígitos. 
  - En el autómata se representa como: LetraLetraLetraLetraLetraDígitoDígito. 
  - Un ejemplo de la expresión puede ser: myVar86. 
- La tercera expresión consiste de una variable que empieza con una letra, es seguida por varias
letras, tiene un underscore y termina con dos dígitos. 
  - En el autómata se representa como: LetraLetraLetraLetraLetraUnderscoreDígitoDígito. 
  - Un ejemplo de la expresión puede ser: myVar_86. 
- La cuarta expresión consiste de una variable que empieza con una letra, es seguida por varias
letras, tiene un underscore, tiene dos dígitos, un underscore y por último vuelve a tener varias
letras. 
  - En el autómata se representa como: LetraLetraLetraLetraLetraUnderscoreDígitoDígitoUnderscoreLetraLetraLetraLetraLetraLetra 
  - Un ejemplo de la expresión puede ser: myVar_86_entero. 
- La quinta expresión consiste de una variable que empieza con un signo negativo, después
tiene una letra, es seguida por varias letras y termina con dos dígitos. 
  - En el autómata se representa como: NegativoLetraLetraLetraLetraLetraDígitoDígito. 
  - Un ejemplo de la expresión puede ser: -myVar86. 
- La sexta expresión consiste de una variable que empieza con un signo negativo, después tiene
una letra, es seguida por varias letras, tiene un underscore y termina con dos dígitos. 
  - En el autómata se representa como: NegativoLetraLetraLetraLetraLetraUnderscoreDígitoDígito. 
  - Un ejemplo de la expresión puede ser: -myVar_86. 
- La séptima expresión consiste de una variable que empieza con un signo negativo, después
tiene una letra, es seguida por varias letras, tiene un underscore, tiene dos dígitos, un
underscore y por último vuelve a tener varias letras. 
  - En el autómata se representa como: 
NegativoLetraLetraLetraLetraLetraUnderscoreDígitoDígitoUnderscoreLetraLetraLetraLetraL
etraLetra 
  - Un ejemplo de la expresión puede ser: -myVar_86_entero. 
- La octava expresión consiste de una variable que solamente tiene una letra. 
  - En el autómata se representa como: Letra. 
  - Un ejemplo de la expresión puede ser: x. 
- La novena expresión consiste de una variable que empieza con signo negativo seguido de una
letra. 
  - En el autómata se representa como: NegativoLetra. 
  - Un ejemplo de la expresión puede ser: -x.

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/55a46d9a-21e3-46fc-9cdc-49b42486dbef)

### Ejemplos de cadenas rechazadas: 
- La primera variable es rechazada porque comienza con un dígito o un underscore. 
  - En el autómata se representa como: UnderscoreLetra 
  - Un ejemplo de la expresión puede ser: _x 
- La segunda variable rechazada contiene un underscore, negativo o dígito después de un signo
negativo. 
  - En el autómata se representa como: NegativoDígitoLetra 
  - Un ejemplo de la expresión puede ser: -6b 
- La tercera variable rechazada tiene un signo negativo en una posición distinta a la primera. 
  - En el autómata se representa como: LetraLetraLetraNegativoLetra 
  - Un ejemplo de la expresión puede ser: var-N
 
![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/b23ce247-805e-4fb4-8c17-1632b43a1115)

## Autómata “b”: Números naturales y reales 
### Ejemplos de cadenas aceptadas: 
- La primera expresión consiste de un número que solamente contiene un dígito 
  - En el autómata se representa como: Dígito. 
  - Un ejemplo de la expresión puede ser: 9. 
- La segunda expresión consiste de un número que varios dígitos 
  - En el autómata se representa como: DígitoDígitoDígito. 
  - Un ejemplo de la expresión puede ser: 983. 
- La tercera expresión consiste de un número que empieza con un dígito y después tiene un
punto seguido de otro dígito 
  - En el autómata se representa como: DígitoPuntoDígito. 
  - Un ejemplo de la expresión puede ser: 9.6. 
- La cuarta expresión consiste de un número que empieza con un dígito, le siguen varios
dígitos, tiene un punto y luego tiene varios dígitos. 
  - En el autómata se representa como: DígitoDígitoDígitoPuntoDígitoDígito. 
  - Un ejemplo de la expresión puede ser: 983.21. 
- La quinta expresión consiste de un número que empieza un dígito, tiene un exponencial y
termina con un dígito. 
  - En el autómata se representa como: DígitoExponencialDígito. 
  - Un ejemplo de la expresión puede ser: 9E7. 
- La sexta expresión consiste de un número que empieza con un dígito, le siguen varios dígitos,
tiene un punto y luego tiene varios dígitos, después tiene un exponencial y al final tiene varios
dígitos. 
  - En el autómata se representa como: 
DígitoDígitoDígitoPuntoDígitoDígitoExponencialDígitoDígito. 
  - Un ejemplo de la expresión puede ser: 983.21E12. 
- La séptima expresión consiste de un número que empieza con un signo negativo seguido de
un dígito. 
  - En el autómata se representa como: NegativoDígito. 
  - Un ejemplo de la expresión puede ser: -9. 
- La octava expresión consiste de un número que empieza con un signo negativo seguido de
varios dígitos, un punto, después otros dígitos, un exponencial, un signo negativo y por último
un dígito. 
  - En el autómata se representa como: 
NegativoDígitoDígitoPuntoDígitoDígitoExponencialNegativoDígito. 
  - Un ejemplo de la expresión puede ser: -97.45E-1.

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/7f2c7c8a-b3f0-4448-8d87-a558a5386675)

### Ejemplos de cadenas rechazadas: 
- El primer número es rechazado ya que empieza con un punto o un exponencial y después le
sigue un dígito. 
  - En el autómata se representa como: PuntoDígito 
  - Un ejemplo de la expresión puede ser: .9 
- El segundo número es rechazado ya que empieza con un dígito, después le sigue un
exponencial y le sigue un segundo exponencial. Cuando después de un punto, exponencial o
signo, se vuelve a repetir cualquier otro de los tres anteriores se presenta error y se rechaza la
cadena. 
  - En el autómata se representa como: DígitoExponencialExponencial 
  - Un ejemplo de la expresión puede ser: 9EE 
- El tercer número rechazado tiene un signo negativo y después le sigue el caracter
exponencial, un punto u otro negativo. 
  - En el autómata se representa como: NegativoPuntoDígito 
  - Un ejemplo de la expresión puede ser: -.8
 
![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/8c8f9241-8017-4409-aac8-c9b6ad001f89)

## Programa C++ 
### ¿En qué lenguaje se hizo el programa?
El programa se realizó en C++ ya que este es un lenguaje orientado a objetos y consideramos que el
utilizar este tipo de programación nos sería útil para resolver el problema planteado del reconocedor
de tokens Lexer. 
### ¿Qué debo instalar? 
- Se hace la instalación de VS Code desde https://code.visualstudio.com/download 
- Debe descargar el programa dependiendo del sistema operativo de su computadora, ya sea si
es Windows, Ubuntu o MacOs. 
![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/339b3cf3-3577-4c46-83b3-f9f6b8402ec1)
 
- Desde Visual Studio Code 
1. Se abre Visual Studio Code y se instalan las siguientes dos extensiones “C/C++
Extension Pack” y “Code Runner”, las cuales se pueden buscar en la pestaña de
“extensiones” en el menú izquierdo.

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/a3315e90-ac30-42d7-b0c2-95f9be57c94c)

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/2d331c2c-a350-4761-b183-67af0bcd6b53)

### ¿Cómo correr el programa? 
1. Descargue los archivos cpp y txt guárdelos en una carpeta juntos. 
2. Abra Visual Studio Code. 
3. Ahora en la pestaña del explorador del menú izquierdo presiona Ctrl + O (esto es para abrir
un archivo) y selecciona la carpeta generada en el explorador de archivos.
4. De click en el archivo cpp llamado “Act3_2_Programando_un_DFA”. 
5. Una vez abierto el programa, en la esquina superior derecha hay un botón de “play” que
funciona para correr el programa .cpp. 
![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/9ebc87a3-b3f6-488d-ac17-8c55f8242f0f)

### ¿Qué se obtiene de salida? 
Al dar click en el botón de correr “Play”, se muestra una pestaña en la parte baja de la ventana la cual
es la terminal. Aquí va a pedir un input, donde se escribe el nombre del archivo txt (en este caso
“lexer.txt”) y al dar enter mostrará el output correspondiente a la expresión o expresiones en el
archivo lexer.txt. Cabe destacarse que, las expresiones en este archivo pueden ser modificadas para
recibir un output diferente. 
## Casos de Prueba 
### Caso 1 
Para el primer caso de prueba el archivo lexer.txt contiene una expresión aritmética con todos sus
caracteres juntos, es decir, sin espacios, de manera que, el programa imprime una tabla con el índice
de la línea donde se encontró el caracter, el token encontrado y el tipo de token. En este caso nuestra
expresión es var_1/my_num=6.32, la cual contiene variables, un operador, asignación y un número
real, y podemos ver en la terminal como se identifica cada token. 

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/00ba0144-065b-4f0b-9f77-393c10b7795c)

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/fabd2d3e-864f-4018-93de-0b25c8fdfd9b)

## Caso 2 
En el segundo caso de prueba se lee un archivo donde solamente existe un comentario que dice //este
es un comentario (123+5)=7. Este comentario contiene texto e incluso una expresión aritmética, sin
embargo, el programa identifica que todo lo contenido después de // pertenece al comentario. El
programa nos indica que encuentra el token que pusimos y que es de tipo comentario. 

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/6405c8d2-f264-4caa-8126-3f68c6d4cb19)

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/3e018304-6f5a-457b-8634-2d0e749b1898)


## Caso 3 
En este caso el archivo lexer.txt contiene una expresión aritmética con espacios entre los operadores,
símbolos y números. Podemos ver en el output de la terminal los índices, en donde ignora los espacios
puestos y va detectando solamente los tokens, así como su tipo. En este caso podemos ver en la
expresión números enteros, números negativos, reales, operadores, y paréntesis.

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/24e5a551-56d6-4cdd-91d6-11f15b321b29)

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/bd451073-275e-4629-a8de-3ca115ac7ff5)


## Caso 4 
En este caso de prueba, el archivo lexer.txt contiene múltiples expresiones aritméticas y, cada una está
compuesta por diferentes tokens como variables, enteros, reales, operadores, paréntesis y comentarios
y también están separados por ninguno, uno o múltiples espacios. Así pues, se puede visualizar que la
tabla con los tokens y sus tipos se imprimió correctamente. 
![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/c4a779c9-358c-4c19-a534-948531f079b5)

![image](https://github.com/Silvana-Ruiz/LexerExpressionParser/assets/67821436/f8b9d0de-f3fd-425d-b0ea-cdb8e672453c)
