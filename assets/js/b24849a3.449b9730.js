"use strict";(self.webpackChunklenguajes_estructurados=self.webpackChunklenguajes_estructurados||[]).push([[864],{3905:(e,a,n)=>{n.d(a,{Zo:()=>c,kt:()=>b});var r=n(7294);function t(e,a,n){return a in e?Object.defineProperty(e,a,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[a]=n,e}function l(e,a){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);a&&(r=r.filter((function(a){return Object.getOwnPropertyDescriptor(e,a).enumerable}))),n.push.apply(n,r)}return n}function i(e){for(var a=1;a<arguments.length;a++){var n=null!=arguments[a]?arguments[a]:{};a%2?l(Object(n),!0).forEach((function(a){t(e,a,n[a])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):l(Object(n)).forEach((function(a){Object.defineProperty(e,a,Object.getOwnPropertyDescriptor(n,a))}))}return e}function o(e,a){if(null==e)return{};var n,r,t=function(e,a){if(null==e)return{};var n,r,t={},l=Object.keys(e);for(r=0;r<l.length;r++)n=l[r],a.indexOf(n)>=0||(t[n]=e[n]);return t}(e,a);if(Object.getOwnPropertySymbols){var l=Object.getOwnPropertySymbols(e);for(r=0;r<l.length;r++)n=l[r],a.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(t[n]=e[n])}return t}var u=r.createContext({}),s=function(e){var a=r.useContext(u),n=a;return e&&(n="function"==typeof e?e(a):i(i({},a),e)),n},c=function(e){var a=s(e.components);return r.createElement(u.Provider,{value:a},e.children)},d="mdxType",p={inlineCode:"code",wrapper:function(e){var a=e.children;return r.createElement(r.Fragment,{},a)}},m=r.forwardRef((function(e,a){var n=e.components,t=e.mdxType,l=e.originalType,u=e.parentName,c=o(e,["components","mdxType","originalType","parentName"]),d=s(n),m=t,b=d["".concat(u,".").concat(m)]||d[m]||p[m]||l;return n?r.createElement(b,i(i({ref:a},c),{},{components:n})):r.createElement(b,i({ref:a},c))}));function b(e,a){var n=arguments,t=a&&a.mdxType;if("string"==typeof e||t){var l=n.length,i=new Array(l);i[0]=m;var o={};for(var u in a)hasOwnProperty.call(a,u)&&(o[u]=a[u]);o.originalType=e,o[d]="string"==typeof e?e:t,i[1]=o;for(var s=2;s<l;s++)i[s]=n[s];return r.createElement.apply(null,i)}return r.createElement.apply(null,n)}m.displayName="MDXCreateElement"},7593:(e,a,n)=>{n.r(a),n.d(a,{assets:()=>u,contentTitle:()=>i,default:()=>p,frontMatter:()=>l,metadata:()=>o,toc:()=>s});var r=n(7462),t=(n(7294),n(3905));const l={marp:!0,theme:"default",size:969,paginate:!0},i="03.01 - Juego de la vida de Conway",o={unversionedId:"Ejercicios Resueltos/03.01_life_conway",id:"Ejercicios Resueltos/03.01_life_conway",title:"03.01 - Juego de la vida de Conway",description:"Lenguajes Estructurados",source:"@site/docs/03 - Ejercicios Resueltos/03.01_life_conway.md",sourceDirName:"03 - Ejercicios Resueltos",slug:"/Ejercicios Resueltos/03.01_life_conway",permalink:"/lenguajes-estructurados/docs/Ejercicios Resueltos/03.01_life_conway",draft:!1,editUrl:"https://github.com/abelranni/lenguajes-estructurados/tree/main/docs/03 - Ejercicios Resueltos/03.01_life_conway.md",tags:[],version:"current",frontMatter:{marp:!0,theme:"default",size:969,paginate:!0},sidebar:"tutorialSidebar",previous:{title:"03 - Ejercicios Resueltos",permalink:"/lenguajes-estructurados/docs/category/03---ejercicios-resueltos"},next:{title:"03.02 - Fractales de Julia",permalink:"/lenguajes-estructurados/docs/Ejercicios Resueltos/03.02_fractales_julia"}},u={},s=[{value:"Lenguajes Estructurados",id:"lenguajes-estructurados",level:2},{value:"Introducci\xf3n",id:"introducci\xf3n",level:2},{value:"Algoritmo",id:"algoritmo",level:2},{value:"Implementaci\xf3n en C",id:"implementaci\xf3n-en-c",level:2}],c={toc:s},d="wrapper";function p(e){let{components:a,...n}=e;return(0,t.kt)(d,(0,r.Z)({},c,n,{components:a,mdxType:"MDXLayout"}),(0,t.kt)("h1",{id:"0301---juego-de-la-vida-de-conway"},"03.01 - Juego de la vida de Conway"),(0,t.kt)("h2",{id:"lenguajes-estructurados"},"Lenguajes Estructurados"),(0,t.kt)("hr",null),(0,t.kt)("h2",{id:"introducci\xf3n"},"Introducci\xf3n"),(0,t.kt)("p",null,"El Juego de la Vida es un aut\xf3mata celular creado por John Horton Conway en 1970.\nConsiste en una cuadr\xedcula de c\xe9lulas que pueden estar vivas o muertas, y evoluciona seg\xfan unas reglas muy simples.\nEn cada turno, las c\xe9lulas que est\xe1n vivas pueden morir por sobrepoblaci\xf3n o por soledad, mientras que las c\xe9lulas que est\xe1n muertas pueden revivir si hay exactamente tres c\xe9lulas vivas adyacentes.\nA pesar de su simplicidad, el Juego de la Vida puede generar patrones complejos y fascinantes."),(0,t.kt)("hr",null),(0,t.kt)("p",null,"En este ejemplo, implementaremos el Juego de la Vida en formato ASCII en C. El programa generar\xe1 un tablero aleatorio de c\xe9lulas vivas y muertas, lo imprimir\xe1 en la consola y lo actualizar\xe1 seg\xfan las reglas del juego."),(0,t.kt)("hr",null),(0,t.kt)("h2",{id:"algoritmo"},"Algoritmo"),(0,t.kt)("p",null,"El algoritmo del Juego de la Vida se puede resumir en los siguientes pasos:"),(0,t.kt)("ul",null,(0,t.kt)("li",{parentName:"ul"},"Se genera un tablero aleatorio de c\xe9lulas vivas y muertas."),(0,t.kt)("li",{parentName:"ul"},"En cada turno, se cuenta el n\xfamero de c\xe9lulas vivas adyacentes a cada c\xe9lula."),(0,t.kt)("li",{parentName:"ul"},"Las c\xe9lulas que est\xe1n vivas pueden morir por sobrepoblaci\xf3n o por soledad, y las c\xe9lulas que est\xe1n muertas pueden revivir si hay exactamente tres c\xe9lulas vivas adyacentes."),(0,t.kt)("li",{parentName:"ul"},"Se actualiza el tablero seg\xfan las c\xe9lulas que han muerto o revivido.")),(0,t.kt)("hr",null),(0,t.kt)("h2",{id:"implementaci\xf3n-en-c"},"Implementaci\xf3n en C"),(0,t.kt)("ul",null,(0,t.kt)("li",{parentName:"ul"},"Para implementar el Juego de la Vida en C, necesitaremos las siguientes bibliotecas:",(0,t.kt)("ul",{parentName:"li"},(0,t.kt)("li",{parentName:"ul"},"Para utilizar la funci\xf3n usleep() es necesario incluir la biblioteca unistd.h."),(0,t.kt)("li",{parentName:"ul"},"Para generar n\xfameros aleatorios, se debe incluir la biblioteca stdlib.h."),(0,t.kt)("li",{parentName:"ul"},"Para utilizar los tipos de datos bool, true y false, se debe incluir la biblioteca stdbool.h."),(0,t.kt)("li",{parentName:"ul"},"Para utilizar la funci\xf3n time() es necesario incluir la biblioteca time.h.")))),(0,t.kt)("pre",null,(0,t.kt)("code",{parentName:"pre",className:"language-c"},"#include <stdio.h>\n#include <stdlib.h>\n#include <stdbool.h>\n#include <time.h>\n#include <unistd.h>\n")),(0,t.kt)("hr",null),(0,t.kt)("ul",null,(0,t.kt)("li",{parentName:"ul"},"Definir las constantes y variables globales\nSe deben definir las constantes ROWS y COLS para especificar el tama\xf1o del tablero, y las variables globales board y new_board para almacenar el estado actual del tablero y el estado nuevo despu\xe9s de cada actualizaci\xf3n.")),(0,t.kt)("pre",null,(0,t.kt)("code",{parentName:"pre",className:"language-c"},"#define ROWS 20\n#define COLS 50\n\nbool board[ROWS][COLS];\nbool new_board[ROWS][COLS];\n")),(0,t.kt)("hr",null),(0,t.kt)("ul",null,(0,t.kt)("li",{parentName:"ul"},"Funci\xf3n para imprimir el tablero\nCrear una funci\xf3n print_board() que imprima el tablero en la consola.")),(0,t.kt)("pre",null,(0,t.kt)("code",{parentName:"pre",className:"language-c"},'void print_board() {\n    for(int i = 0; i < ROWS; i++) {\n        for(int j = 0; j < COLS; j++) {\n            if(board[i][j]) {\n                printf("*");\n            } else {\n                printf(" ");\n            }\n        }\n        printf("\\n");\n    }\n}\n')),(0,t.kt)("hr",null),(0,t.kt)("ul",null,(0,t.kt)("li",{parentName:"ul"},"Funci\xf3n para inicializar el tablero aleatoriamente\nLa funci\xf3n init_board() debe inicializar cada celda del tablero aleatoriamente, utilizando la funci\xf3n rand().\nEn este ejemplo, se utilizar\xe1 una semilla basada en la hora actual para generar valores pseudoaleatorios.")),(0,t.kt)("pre",null,(0,t.kt)("code",{parentName:"pre",className:"language-c"},"void init_board() {\n    srand(time(NULL));\n    for(int i = 0; i < ROWS; i++) {\n        for(int j = 0; j < COLS; j++) {\n            board[i][j] = rand() % 2;\n        }\n    }\n}\n")),(0,t.kt)("hr",null),(0,t.kt)("ul",null,(0,t.kt)("li",{parentName:"ul"},"Funci\xf3n para contar c\xe9lulas vivas adyacentes\nSe debe crear una funci\xf3n count_neighbors(row, col) que cuente el n\xfamero de c\xe9lulas vivas adyacentes a una c\xe9lula dada en una posici\xf3n (row, col) del tablero.")),(0,t.kt)("pre",null,(0,t.kt)("code",{parentName:"pre",className:"language-c"},"int count_neighbors(int row, int col) {\n    int count = 0;    \n    for(int i = row - 1; i <= row + 1; i++) {\n        for(int j = col - 1; j <= col + 1; j++) {\n            if(i == row && j == col) {\n                continue;\n            }\n            if(i < 0 || i >= ROWS || j < 0 || j >= COLS) {\n                continue;\n            }\n            if(board[i][j]) {\n                count++;\n            }\n        }\n    }\n    return count;\n}\n")),(0,t.kt)("hr",null),(0,t.kt)("ul",null,(0,t.kt)("li",{parentName:"ul"},"Funci\xf3n para actualizar el tablero\nSe debe crear una funci\xf3n update_board() que actualice el tablero seg\xfan las c\xe9lulas que han muerto o revivido.\nPara hacerlo, se debe:",(0,t.kt)("ul",{parentName:"li"},(0,t.kt)("li",{parentName:"ul"},"iterar sobre cada celda del tablero"),(0,t.kt)("li",{parentName:"ul"},"contar el n\xfamero de c\xe9lulas vivas adyacentes a cada celda"),(0,t.kt)("li",{parentName:"ul"},"aplicar las reglas del Juego de la Vida para determinar si la c\xe9lula debe morir o revivir.")))),(0,t.kt)("hr",null),(0,t.kt)("pre",null,(0,t.kt)("code",{parentName:"pre",className:"language-c"},"void update_board() {\n    for(int i = 0; i < ROWS; i++) {\n        for(int j = 0; j < COLS; j++) {\n            int neighbors = count_neighbors(i, j);\n\n            if(board[i][j]) {\n                if(neighbors < 2 || neighbors > 3) {\n                    new_board[i][j] = false;\n                } else {\n                    new_board[i][j] = true;\n                }\n            } else {\n                if(neighbors == 3) {\n                    new_board[i][j] = true;\n                } else {\n                    new_board[i][j] = false;\n                }\n            }\n        }\n    }\n\n    for(int i = 0; i < ROWS; i++) {\n        for(int j = 0; j < COLS; j++) {\n            board[i][j] = new_board[i][j];\n        }\n    }\n}\n")),(0,t.kt)("hr",null),(0,t.kt)("ul",null,(0,t.kt)("li",{parentName:"ul"},"Funci\xf3n principal\nPor \xfaltimo, se debe crear la funci\xf3n principal main() que inicializa el tablero aleatoriamente, entra en un bucle infinito en el que se imprime el tablero, se actualiza el tablero y se espera un corto per\xedodo de tiempo antes de repetir el proceso.")),(0,t.kt)("pre",null,(0,t.kt)("code",{parentName:"pre",className:"language-c"},'int main() {\n    init_board();\n\n    while(true) {\n        system("cls"); // Limpia la pantalla en sistemas Windows\n        print_board();\n        update_board();\n        usleep(100000); // Espera 100 milisegundos\n    }\n\n    return 0;\n}\n')))}p.isMDXComponent=!0}}]);