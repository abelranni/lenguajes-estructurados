"use strict";(self.webpackChunklenguajes_estructurados=self.webpackChunklenguajes_estructurados||[]).push([[7032],{3905:(e,n,a)=>{a.d(n,{Zo:()=>u,kt:()=>k});var t=a(7294);function r(e,n,a){return n in e?Object.defineProperty(e,n,{value:a,enumerable:!0,configurable:!0,writable:!0}):e[n]=a,e}function l(e,n){var a=Object.keys(e);if(Object.getOwnPropertySymbols){var t=Object.getOwnPropertySymbols(e);n&&(t=t.filter((function(n){return Object.getOwnPropertyDescriptor(e,n).enumerable}))),a.push.apply(a,t)}return a}function o(e){for(var n=1;n<arguments.length;n++){var a=null!=arguments[n]?arguments[n]:{};n%2?l(Object(a),!0).forEach((function(n){r(e,n,a[n])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(a)):l(Object(a)).forEach((function(n){Object.defineProperty(e,n,Object.getOwnPropertyDescriptor(a,n))}))}return e}function p(e,n){if(null==e)return{};var a,t,r=function(e,n){if(null==e)return{};var a,t,r={},l=Object.keys(e);for(t=0;t<l.length;t++)a=l[t],n.indexOf(a)>=0||(r[a]=e[a]);return r}(e,n);if(Object.getOwnPropertySymbols){var l=Object.getOwnPropertySymbols(e);for(t=0;t<l.length;t++)a=l[t],n.indexOf(a)>=0||Object.prototype.propertyIsEnumerable.call(e,a)&&(r[a]=e[a])}return r}var i=t.createContext({}),c=function(e){var n=t.useContext(i),a=n;return e&&(a="function"==typeof e?e(n):o(o({},n),e)),a},u=function(e){var n=c(e.components);return t.createElement(i.Provider,{value:n},e.children)},s="mdxType",d={inlineCode:"code",wrapper:function(e){var n=e.children;return t.createElement(t.Fragment,{},n)}},m=t.forwardRef((function(e,n){var a=e.components,r=e.mdxType,l=e.originalType,i=e.parentName,u=p(e,["components","mdxType","originalType","parentName"]),s=c(a),m=r,k=s["".concat(i,".").concat(m)]||s[m]||d[m]||l;return a?t.createElement(k,o(o({ref:n},u),{},{components:a})):t.createElement(k,o({ref:n},u))}));function k(e,n){var a=arguments,r=n&&n.mdxType;if("string"==typeof e||r){var l=a.length,o=new Array(l);o[0]=m;var p={};for(var i in n)hasOwnProperty.call(n,i)&&(p[i]=n[i]);p.originalType=e,p[s]="string"==typeof e?e:r,o[1]=p;for(var c=2;c<l;c++)o[c]=a[c];return t.createElement.apply(null,o)}return t.createElement.apply(null,a)}m.displayName="MDXCreateElement"},4544:(e,n,a)=>{a.r(n),a.d(n,{assets:()=>i,contentTitle:()=>o,default:()=>d,frontMatter:()=>l,metadata:()=>p,toc:()=>c});var t=a(7462),r=(a(7294),a(3905));const l={marp:!0,theme:"default",size:969,paginate:!0},o="Punteros en C",p={unversionedId:"Lenguaje C/Punteros/punteros",id:"Lenguaje C/Punteros/punteros",title:"Punteros en C",description:"Lenguajes Estructurados",source:"@site/docs/02 - Lenguaje C/Punteros/1.punteros.md",sourceDirName:"02 - Lenguaje C/Punteros",slug:"/Lenguaje C/Punteros/punteros",permalink:"/lenguajes-estructurados/docs/Lenguaje C/Punteros/punteros",draft:!1,editUrl:"https://github.com/abelranni/lenguajes-estructurados/tree/main/wewbsite/docs/02 - Lenguaje C/Punteros/1.punteros.md",tags:[],version:"current",sidebarPosition:1,frontMatter:{marp:!0,theme:"default",size:969,paginate:!0},sidebar:"tutorialSidebar",previous:{title:"02.05 - Manejo de memoria",permalink:"/lenguajes-estructurados/docs/Lenguaje C/02.05_memoria"},next:{title:"Relaci\xf3n entre matrices y punteros",permalink:"/lenguajes-estructurados/docs/Lenguaje C/Punteros/punteros_y_matrices"}},i={},c=[{value:"Lenguajes Estructurados",id:"lenguajes-estructurados",level:2},{value:"Direcci\xf3n en C",id:"direcci\xf3n-en-c",level:2},{value:"Punteros en C",id:"punteros-en-c-1",level:2},{value:"Sintaxis del puntero",id:"sintaxis-del-puntero",level:3},{value:"Asignaci\xf3n de direcciones a punteros",id:"asignaci\xf3n-de-direcciones-a-punteros",level:3},{value:"Obtener valor de la cosa se\xf1alada por punteros",id:"obtener-valor-de-la-cosa-se\xf1alada-por-punteros",level:3},{value:"Cambio del valor se\xf1alado por punteros",id:"cambio-del-valor-se\xf1alado-por-punteros",level:3},{value:"Ejemplo: Funcionamiento de punteros",id:"ejemplo-funcionamiento-de-punteros",level:3},{value:"Errores comunes al trabajar con punteros",id:"errores-comunes-al-trabajar-con-punteros",level:3}],u={toc:c},s="wrapper";function d(e){let{components:n,...l}=e;return(0,r.kt)(s,(0,t.Z)({},u,l,{components:n,mdxType:"MDXLayout"}),(0,r.kt)("h1",{id:"punteros-en-c"},"Punteros en C"),(0,r.kt)("h2",{id:"lenguajes-estructurados"},"Lenguajes Estructurados"),(0,r.kt)("hr",null),(0,r.kt)("p",null,"Contenido:"),(0,r.kt)("ul",null,(0,r.kt)("li",{parentName:"ul"},"qu\xe9 son los punteros"),(0,r.kt)("li",{parentName:"ul"},"c\xf3mo se los usa"),(0,r.kt)("li",{parentName:"ul"},"errores comunes al trabajar con ellos con la ayuda de ejemplos")),(0,r.kt)("hr",null),(0,r.kt)("h2",{id:"direcci\xf3n-en-c"},"Direcci\xf3n en C"),(0,r.kt)("p",null,"Si tenemos una variable ",(0,r.kt)("inlineCode",{parentName:"p"},"var")," en un programa, ",(0,r.kt)("inlineCode",{parentName:"p"},"&var")," nos dar\xe1 su direcci\xf3n asignada en la memoria."),(0,r.kt)("p",null,"Hemos usado la direcci\xf3n en numerosas ocasiones mientras us\xe1bamos la funci\xf3n.",(0,r.kt)("inlineCode",{parentName:"p"},"scanf()")),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},'scanf("%d", &var);\n')),(0,r.kt)("p",null,"Aqu\xed, el valor introducido por el usuario se almacena en la direcci\xf3n de la variable. Tomemos un ejemplo pr\xe1ctico con el uso de ",(0,r.kt)("inlineCode",{parentName:"p"},"var")),(0,r.kt)("hr",null),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},'#include <stdio.h>\nint main()\n{\n  int var = 5;\n  printf("var: %d\\n", var);\n\n  // Observar el uso de & antes de var\n  printf("direccion de var: %p", &var);\n  return 0;\n}\n')),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"Salida"),"\nvar: 5\ndireccion de var: 2686778"),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"Nota:"),"\xa0Probablemente se obtendr\xe1 una direcci\xf3n diferente cuando ejecute el c\xf3digo anterior."),(0,r.kt)("hr",null),(0,r.kt)("h2",{id:"punteros-en-c-1"},"Punteros en C"),(0,r.kt)("p",null,"Los punteros (variables de puntero) son variables especiales que se utilizan para almacenar direcciones en lugar de valores."),(0,r.kt)("h3",{id:"sintaxis-del-puntero"},"Sintaxis del puntero"),(0,r.kt)("p",null,"As\xed es como podemos declarar punteros."),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},"int* p;\n")),(0,r.kt)("p",null,"Aqu\xed, hemos declarado un puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"p")," de tipo ",(0,r.kt)("inlineCode",{parentName:"p"},"int")),(0,r.kt)("p",null,"Tambi\xe9n puede declarar punteros de estas maneras."),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},"int *p1;\nint * p2;\n")),(0,r.kt)("hr",null),(0,r.kt)("p",null,"Tomemos otro ejemplo de declaraci\xf3n de punteros."),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},"int* p1, p2;\n")),(0,r.kt)("p",null,"Aqu\xed, hemos declarado un puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"p1")," y una variable normal ",(0,r.kt)("inlineCode",{parentName:"p"},"p2")),(0,r.kt)("h3",{id:"asignaci\xf3n-de-direcciones-a-punteros"},"Asignaci\xf3n de direcciones a punteros"),(0,r.kt)("p",null,"Tomemos un ejemplo."),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},"int* pc, c;\nc = 5;\npc = &c;\n")),(0,r.kt)("p",null,"Aqu\xed, 5 se asigna a la variable ",(0,r.kt)("inlineCode",{parentName:"p"},"c"),". Y, la direcci\xf3n de ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," se asigna al puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"pc")),(0,r.kt)("hr",null),(0,r.kt)("h3",{id:"obtener-valor-de-la-cosa-se\xf1alada-por-punteros"},"Obtener valor de la cosa se\xf1alada por punteros"),(0,r.kt)("p",null,"Para obtener el valor de la cosa apuntada por los punteros, usamos el operador ",(0,r.kt)("inlineCode",{parentName:"p"},"*"),". Por ejemplo:"),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},'int* pc, c;\nc = 5;\npc = &c;\nprintf("%d", *pc);   // Output: 5\n')),(0,r.kt)("p",null,"Aqu\xed, la direcci\xf3n de ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," se asigna al puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"pc"),". Para obtener el valor almacenado en esa direcci\xf3n, usamos ",(0,r.kt)("inlineCode",{parentName:"p"},"*pc")),(0,r.kt)("blockquote",null,(0,r.kt)("p",{parentName:"blockquote"},(0,r.kt)("strong",{parentName:"p"},"Nota:"),"\xa0En el ejemplo anterior, ",(0,r.kt)("inlineCode",{parentName:"p"},"pc")," es un puntero, no ",(0,r.kt)("inlineCode",{parentName:"p"},"*pc")," . No puedes y no debes hacer algo como\xa0",(0,r.kt)("inlineCode",{parentName:"p"},"*pc = &c"),";\nPor cierto, ",(0,r.kt)("inlineCode",{parentName:"p"},"*")," se llama operador de dereferenciaci\xf3n o indirecci\xf3n (cuando se trabaja con punteros). Opera en un puntero y da el valor almacenado en ese puntero.")),(0,r.kt)("hr",null),(0,r.kt)("h3",{id:"cambio-del-valor-se\xf1alado-por-punteros"},"Cambio del valor se\xf1alado por punteros"),(0,r.kt)("p",null,"Tomemos un ejemplo."),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},'int* pc, c;\nc = 5;\npc = &c;\nc = 1;\nprintf("%d", c);    // Output: 1\nprintf("%d", *pc);  // Ouptut: 1\n')),(0,r.kt)("p",null,"Hemos asignado la direcci\xf3n de ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," al puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"pc")),(0,r.kt)("p",null,"Luego, cambiamos el valor de ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," a 1. Dado que ",(0,r.kt)("inlineCode",{parentName:"p"},"pc")," y la direcci\xf3n de ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," es la misma, ",(0,r.kt)("inlineCode",{parentName:"p"},"*pc")," nos da 1."),(0,r.kt)("hr",null),(0,r.kt)("p",null,"Tomemos otro ejemplo."),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},'int* pc, c;\nc = 5;\npc = &c;\n*pc = 1;\nprintf("%d", *pc);  // Ouptut: 1\nprintf("%d", c);    // Output: 1\n')),(0,r.kt)("p",null,"Hemos asignado la direcci\xf3n de ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," al puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"pc")),(0,r.kt)("p",null,"Luego, cambiamos ",(0,r.kt)("inlineCode",{parentName:"p"},"*pc")," a 1 usando ",(0,r.kt)("inlineCode",{parentName:"p"},"*pc = 1"),". Dado que ",(0,r.kt)("inlineCode",{parentName:"p"},"pc")," y la direcci\xf3n de ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," es la misma, ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," ser\xe1 igual a 1."),(0,r.kt)("hr",null),(0,r.kt)("p",null,"Tomemos un ejemplo m\xe1s."),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},'int* pc, c, d;\nc = 5;\nd = -15;\n\npc = &c; printf("%d", *pc); // Output: 5\npc = &d; printf("%d", *pc); // Ouptut: -15\n')),(0,r.kt)("p",null,"Inicialmente, la direcci\xf3n de ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," se asigna al puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"pc")," mediante ",(0,r.kt)("inlineCode",{parentName:"p"},"pc = &c;"),". Como ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," es 5, ",(0,r.kt)("inlineCode",{parentName:"p"},"*pc")," nos da 5."),(0,r.kt)("p",null,"A continuaci\xf3n, la direcci\xf3n de ",(0,r.kt)("inlineCode",{parentName:"p"},"d")," se asigna al puntero mediante ",(0,r.kt)("inlineCode",{parentName:"p"},"pc = &d;"),". Como ",(0,r.kt)("inlineCode",{parentName:"p"},"d")," es -15, ",(0,r.kt)("inlineCode",{parentName:"p"},"*pc")," nos da -15."),(0,r.kt)("hr",null),(0,r.kt)("h3",{id:"ejemplo-funcionamiento-de-punteros"},"Ejemplo: Funcionamiento de punteros"),(0,r.kt)("p",null,"Tomemos un ejemplo pr\xe1ctico."),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},'#include <stdio.h>\nint main()\n{\n   int* pc, c;\n\n   c = 22;\n   printf("Direccion de c: %p\\n", &c);\n   printf("Valor de c: %d\\n\\n", c);  // 22\n\n   pc = &c;\n   printf("Direccion del puntero pc: %p\\n", pc);\n   printf("Contenido del puntero pc: %d\\n\\n", *pc); // 22\n\n   c = 11;\n   printf("Direccion del puntero pc: %p\\n", pc);\n   printf("Contenido del puntero pc: %d\\n\\n", *pc); // 11\n\n   *pc = 2;\n   printf("Direccion de c: %p\\n", &c);\n   printf("Valor de c: %d\\n\\n", c); // 2\n   return 0;\n}\n')),(0,r.kt)("hr",null),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"Salida")),(0,r.kt)("p",null,"Direccion de c: 2686784\nValor de c: 22"),(0,r.kt)("p",null,"Direccion del puntero pc: 2686784\nContenido del puntero pc: 22"),(0,r.kt)("p",null,"Direccion del puntero pc: 2686784\nContenido del puntero pc: 11"),(0,r.kt)("p",null,"Direccion de c: 2686784\nValor de c: 2"),(0,r.kt)("hr",null),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"Explicaci\xf3n del programa")),(0,r.kt)("ul",null,(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("p",{parentName:"li"},(0,r.kt)("inlineCode",{parentName:"p"},"int* pc, c;")),(0,r.kt)("p",{parentName:"li"},"  ",(0,r.kt)("img",{alt:"Se crea una variable de puntero y una variable normal.",src:a(6728).Z,width:"120",height:"103"})),(0,r.kt)("p",{parentName:"li"},"  Aqu\xed, se crea un puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"pc")," y una variable normal ",(0,r.kt)("inlineCode",{parentName:"p"},"c"),", ambos de tipo ",(0,r.kt)("inlineCode",{parentName:"p"},"int"),".",(0,r.kt)("br",{parentName:"p"}),"\n","Dado que ",(0,r.kt)("inlineCode",{parentName:"p"},"pc")," y ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," no se inicializan inicialmente, el puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"pc")," no apunta a ninguna direcci\xf3n o a una direcci\xf3n aleatoria. Y, la variable ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," tiene una direcci\xf3n pero contiene un valor de basura aleatorio."))),(0,r.kt)("hr",null),(0,r.kt)("ul",null,(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("p",{parentName:"li"},(0,r.kt)("inlineCode",{parentName:"p"},"c = 22;")),(0,r.kt)("p",{parentName:"li"},"  ",(0,r.kt)("img",{alt:"22 se asigna a la variable c.",src:a(926).Z,width:"120",height:"97"})),(0,r.kt)("p",{parentName:"li"},"  Esto asigna 22 a la variable ",(0,r.kt)("inlineCode",{parentName:"p"},"c"),". Es decir, 22 se almacena en la ubicaci\xf3n de memoria de la variable ",(0,r.kt)("inlineCode",{parentName:"p"},"c"),".")),(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("p",{parentName:"li"},(0,r.kt)("inlineCode",{parentName:"p"},"pc = &c;")),(0,r.kt)("p",{parentName:"li"},"  ",(0,r.kt)("img",{alt:"La direcci\xf3n de la variable c se asigna al puntero pc.",src:a(3459).Z,width:"120",height:"97"})),(0,r.kt)("p",{parentName:"li"},"  Esto asigna la direcci\xf3n de variable ",(0,r.kt)("inlineCode",{parentName:"p"},"c")," al puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"pc"),"."))),(0,r.kt)("hr",null),(0,r.kt)("ul",null,(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("p",{parentName:"li"},(0,r.kt)("inlineCode",{parentName:"p"},"c = 11;")),(0,r.kt)("p",{parentName:"li"},"  ",(0,r.kt)("img",{alt:"11 se asigna a la variable c.",src:a(9714).Z,width:"121",height:"102"})),(0,r.kt)("p",{parentName:"li"},"  Esto asigna 11 a variable ",(0,r.kt)("inlineCode",{parentName:"p"},"c"),".")),(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("p",{parentName:"li"},(0,r.kt)("inlineCode",{parentName:"p"},"*pc = 2;")),(0,r.kt)("p",{parentName:"li"},"  ",(0,r.kt)("img",{alt:"5 se asigna a la direcci\xf3n de la variable de puntero.",src:a(6836).Z,width:"119",height:"100"})),(0,r.kt)("p",{parentName:"li"},"  Esto cambia el valor en la ubicaci\xf3n de memoria se\xf1alada por el puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"pc"),"a 2."))),(0,r.kt)("hr",null),(0,r.kt)("h3",{id:"errores-comunes-al-trabajar-con-punteros"},"Errores comunes al trabajar con punteros"),(0,r.kt)("p",null,"Supongamos que desea que el puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"pc")," apunte a la direcci\xf3n de ",(0,r.kt)("inlineCode",{parentName:"p"},"c"),". Entonces:"),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},"int c, *pc;\n\n// pc es una direccion pero c no\npc = c;  // Error\n\n// &c es una direcci\xf3n pero *pc no\n*pc = &c;  // Error\n\n// ambos &c and pc son direcciones\npc = &c;  // OK\n\n// ambos c y *pc son valores\n*pc = c;  // OK\n\n")),(0,r.kt)("hr",null),(0,r.kt)("p",null,"Aqu\xed hay un ejemplo de sintaxis de puntero que a menudo suele encontrarse confusa."),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},'#include <stdio.h>\nint main() {\n   int c = 5;\n   int *p = &c;\n\n   printf("%d", *p);  // 5\n\xa0  return 0;\n}\n')),(0,r.kt)("hr",null),(0,r.kt)("p",null,(0,r.kt)("strong",{parentName:"p"},"\xbfPor qu\xe9 no obtuvimos un error al usar ?",(0,r.kt)("inlineCode",{parentName:"strong"},"int\xa0*p = &c;"))),(0,r.kt)("p",null,"Es porque"),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},"int *p = &c;\n")),(0,r.kt)("p",null,"es equivalente a"),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},"int *p:\np = &c;\n")),(0,r.kt)("p",null,"En ambos casos, estamos creando un puntero ",(0,r.kt)("inlineCode",{parentName:"p"},"p")," (no ",(0,r.kt)("inlineCode",{parentName:"p"},"*p"),") y asign\xe1ndolo a ",(0,r.kt)("inlineCode",{parentName:"p"},"&c"),"."),(0,r.kt)("p",null,"Para evitar esta confusi\xf3n, podemos usar la declaraci\xf3n de esta manera:"),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-c"},"int* p = &c;\n")),(0,r.kt)("hr",null))}d.isMDXComponent=!0},6728:(e,n,a)=>{a.d(n,{Z:()=>t});const t="data:image/webp;base64,UklGRu4CAABXRUJQVlA4IOICAACwFACdASp4AGcAPlEij0SjoiGYmNScOAUEs4Bp5upagnAkBPpZ22fPN6a9vReRH+FumfXOf1zOGf2mbFv8BrCH8681LOf82epD/Uf9t11fRA/VVHdhgU4HkwlRk3OE997tmMqoVVra66dqNTbTR800suuoUmRvSeFX0kwvQomCureGkil7ZGoXwRX1Ik6X6JJTlTff5nwlUh+rMgnNdbnx0R5AAlWf3SKtBzxdIgAA/v3Av0rml3rOGsAGa6LbMRHH40gy/Mse8g5wNAvyVjA/DvhVIAr/wXv8I/2zjGlA9KWs8O4l0IdWZeEDt69btjg2ucbfKBhnUrKGnA316CP+g9UTQwMuTREXj2Gv7V5Zj2qd31PtZ1ypDS76891BfwL/8MtpzxLjOZ7w9rlNClKTHgj4iyRovDX5O2HG/QBVtONbNzvnUgEaGFa/blM5M9vtXmbr4abJwzk52vLIyQAHWWflsNdimTYCeFJzypxDfBVYW9GDYU99wUYc38/5l0vM798CrDZxn//5F0ByAXZ43tF1LF8K3KaQP/8e2GZ5OOX0nyfDKNVvgG48D15Ge90CXj44dD3wA0G918ejDuupuyfOiLxpkmA+3ug3giFZKi4Oth45F5qRnnQ+F94+EjteCQxFuLR11VkIPWOChQTjRiWco8RS8qjA21Dw216UIPtCQWVRgXIcz/QOqbPJC5a2w6wYEpNspo2v8FsH1i6wQoIvCwDksGZB8mf72FWWqBtdAljXPkmNy3HjpBLnqqO/QWeK68Yrf8gPs4O4XYqRqJEyf1m2exyt3TIuqlP/GpFdUbIsGWqHiMGLHD2qa/QLAvwZ3QEyxu2Oxto9qLO8Nun0Moy20XT0vWxg2MYFfygryJc1OExOPuUk3xePI7x++as/mcDJBLVeuNscVlYg6AW2JM2HApX/WKqOe3gH2S6BX5sJ6SE4Mq2faPD1O3+dcphB+jFKQydvHpFYuAAAAAA="},926:(e,n,a)=>{a.d(n,{Z:()=>t});const t="data:image/webp;base64,UklGRq4DAABXRUJQVlA4IKIDAADwFwCdASp4AGEAPlEkj0YjoaEhIlQL2HAKCWcA1Z0iCL7YDniNNQ9ADpjche8gf0DRDTzX7HnIP75ju/8L9o3m4yjf5F/jNRj/1f656gP+n5Qfm7/je4d/JP53/q/7X2S/RE/XQovgmoWPxd/ZzEz0CkiTXzWODZNrQh8UohSdX8VFPYWsqTUQ6llUU4YiByq72zwSzV0A/5DmZPfMtDMbmyzL98Oj5kEDzecVxBshWT8oufO548+fWZXR1tJYQuv1+wQ1swZ8AAD+/cDjEmuU3qZTmV4YP2nnifwFX+h9XPFrA88fRR/NQ6B4/Uf/L4c7VmYXx+sco7Rvk993N6YSdD6R+0TkhCGdGL/7at95/+8iE6967a5gpynavh9+TyiVsGQ+5ec+WeOnrp0x7o+5s9RebYuCtX0Zgfmzlg5/ISSZSf0yoZPWvP8J4Xxvz+biYqk8xN/lPd10l/ATjj8xhjfHIHeGFInET7Kr+/m/c5f6h7F3XXsJHxB8JDKpYL1u4QFt1Cg+Xo3QzzXDhz+TdYlagz9iKiVVk36IPyF90OxkNKswCufQuupNo+Dee04DNdoj7/6eq2cPT3S3+wBXJdS8DW63/yurVY7XKA0x9VECyqyWk8jJ7FRn8m7BUWFG1eENyqYVXGwYIs+PauvMGAmkk2YSFfIgRlDj+0EXTSgwBdYbvnT0Lt/RpqGcUAbQh+zgDexBGmG9ZF3xQjklAmwfFOBDzUk3Ri/dbI28XKbKBMFEMIGTIn5c1t0Wd8GfzbuX+cpM2wAFTg1k3v3hhwYWfk8TZFo6peBUTz2vpWem8iK9/2cxHg+s/pOOvMzFfYSy6Xdr1/sGjf7UTYitelKI3rY7RA3wBFy8DlLIfkfe+U8kf9C9i7OoOEucWrYfLisrswRirY/lUJzcq9iuI/hI/AClryYFSCSTa00CkS7/V+G8sHMkBD/oVUAIrpPkEqtj0N96hnyksZgACCaEGDL/8xjNn3g0JMhhByXoQAZ8SLsRcpzsETe4u7GDz//McAqtyu+YSB9LL09Qej5Yp+KWaY6IYJdZoZk5+OYi1oGZAHtv5+yIJah/YBeMuIN1QL4rPoeCxEACbvFBrKWXLkQRwrP+XP6Q4EDfhjyHyi9VZUXCBf/izQ6IMafayz+foxC7ebYDCL7+hhXrXJc7AC9BX1jbiLPwOVGJpToDoF+FFUQQSk95ZykU+tVeHxZ5f+klF/IK/WP98UMgAAAAAAA="},3459:(e,n,a)=>{a.d(n,{Z:()=>t});const t="data:image/webp;base64,UklGRhwEAABXRUJQVlA4IBAEAABQGwCdASp4AGEAPlEij0WjoaEQ6q5oOAUEs4BqGrOeBwLNszzrnoA3k30GuloyF7qb2Uf4Xn3/DPqTkr3r2cW/vGSL/B/9N+WPlqSkv51/fPyw5gaY7/Nf+t6V/+L5Vvo//p+4V/GP5n/sfzg/sHIgfsyXiHuCBcso1BXX/zO57Iosn8cfWswKVXLbLns2mWE8eRhymZOA780F/N7vQyylaSerBzf+fHPjQkz1uQpeXKk/dj18g2AwTAoTSv+PjgDtkZ+nlB/EmfoLLOgiMSkDcLWWl95Whdud3CsL82D5lDaIAAD+/cD4j0EITI/Su85GtHEwcFc2xu2loufRLmMOTRW6OuQPgqgyM2n9ktGjKXfrTxX/3Bf/lfXf0YYW09sm+VfH1V1d/jlgyqTKeV4cYqWf/8oSk7Pw+4n+HtebJP/mS38bcpmnPlPrwF+elqvbaySnhBnj1H2Q46zze7SmQSwWAmzItqdmdOBlGsKxwX3A0TUBMs8RzsEnwnNZYWitCa2ieLD5ohaZpwiKzD8bKYZeGR9C/uxqSkQMzcn6NgKJK28t/5rw+BotLOocmn8W+jZhKjGIL+o7lIZ3/MePC28n+XBXKfG5PissIdvspsj+DdHQs+576HpE1Z4uKXHWS//M9vp6vgLFbbDDArmGk1sKX+hwdCohVsRpDkHdcbjz99Xcnl60i71sAOvVviv2gzepIZl/But4OZ7Ws8F0/FLfeYNUWz6k4ACXYRUlbJk2GU2OGvpXJ4zrNX/UoJLz43/9Ke/1v+T9X6lE5mmb/4pqvYFJB/j/Ck1r2W6ykZ1VC8CjfbOCj6MBOPonPFek9hRKIRQqn1XHxs1QLnatcA/L0JPZ3/XdTQj86s4f9K5Y/CXoesBieLTXYKM9F+atQMUpR2Fm6+KLICFtlSwbOnWJ/4MKHdEz76v0omoWf/QoGD29lJwTR4ZOnbGtNFV00kL/lssDbvt7+yqSoMP+CknC9FnL/xipY5/dkLzUKsP/ybfn39jCCh1oP1VgsMvrWK8balLSHKlY1ww9Oocb1ZHiFME53fTE6J3BM9YZSSOHcHL4AbR9AArCAIQPfNmxDGlDuMhOJL3vROduLzf/+nIFkQnAnXsd7IomGob+iKADLZBfbVwJCg8D732pyKnTun21/kLV/dX3NK4vc6sDIJNBPII2hblWFD4P12+yHHXTdC45Ss2U9+kofuit9KWNXPiVkwhFQbZp7K0x3Q4UHJ/ijGW/9n3wY/g2hTdIhZzypVJzjOGbMAZQ0esXsEKa02ny/75vfZZ+X5lZag8R7lQIzbB1la6U2PJ3Isy2xr479WRbDX/zf1JVAY4jFCgu5B9ad1BLCmhAfm2ZoNOL9dX/Vf+x82Oy0gAAAAAAAA=="},9714:(e,n,a)=>{a.d(n,{Z:()=>t});const t="data:image/webp;base64,UklGRtgDAABXRUJQVlA4IMwDAACQGgCdASp5AGYAPlEgi0QjoiEZuPS4OAUEsoBostMEW25nND+oDeLfRA6YLIlvJf9A7Tf7FwpuTDe1/j16Qf0ncAbwRw3+W/5P8pNUJ/yPpN+oHID/0z/Y/kB7vP935Yvyb+5f8X3B/5H/Qf9r15vQiLjulVbJ63ZjCtFSUHUCUpRaSU+3PKzCW436aYfsTBOZaLPDPyTlWVh3oso4ARS17S2tCOZ4dZVblMX7xKXV05Vq5Ob9x4zGAYzPntP3lv5SulgOcoqW4T2XFpVRC1x5mH6ZmiH3/n+aKKR8QAD+/XaXd2onkRDsEtGqdUumV19svn9R8Tsy9dvPVqgChec1eb0VsaOTy1PP/bGZKrkb28F+WS31ZxOZoYMagCOFpND29dB7MUMGHGJHXVXa3Eman7LiI+u7RPl2mYnjAO3svGKyPZE9N0GB87IFk40mLlgewbPP08cmQ9kLcs+LktriVjPoWH8NPzWFwneP+XEP/5+pKW2xldeye7+8Pam+L95HbScyNhhUhIeKjbY1/szTAQcPKNBU+GZX8yW3LrgfFnfQA3AOKTyu1ThW1EEmu6G9U86NGv9Te/NCCEj3/1mVjwEF2TsDY3v6ZmLepuM+ESZb0sXuwTBC3ETdc8CAKNlN1jMIIjj4/eN//LkcEX5kfzkSKnYhaDVor9ebE8jrd/fKktmv1drcvTubiHVINSVDt/iP/2Bu+g/F1iC8sSoUUVu8W4UpljhqKdpv/6AAVxY1Pr0YuNkALra4moM4sGqciIVFrArP0VUVEAdhPKGnN/eDpYlhquRqQTu/P649kufbQdF0mzXOCMJadjkrSTyWTot/ulGyd8p1WH8RiTC/6DQg0F9TWdvn9Z6VrktuX2ZggDVa5n01/+otAWlLbdg1ZnQPr/m5079t/0bxoky4/FnfQ9cKRpCdNwvD4BoUK+u/JpCDBMFqpjVGErFoS8HLhhU8jLtsHyOXkl7WF0OVQOn+nto5x/BlMc/OzLK4IZrVg0yj7V5VP4Tkmx3+DKcKPBp7JLe0eyXLMACEDL5ps48Y2l+DO6Epzf8RkWtb/CGJd7ypqampJY52HD1YiEwERjafWASSRmh9yeJbu2/+ZUisG0jjnR2bzuP2xh1LMOEy1EUrsUr7B8v4To4IGtD5C2DBNbAO/Bw+BYhpr4NNS+RG/3VzmbkIjUjxkgBGe3mhl1/sRsnuoZd3wnPErf/kuvQr55aNVgcWtDWJcqZYMiKXf2ee+DuiDxw+US34ii7L6YnDupE1lSHw6muCBKGMYfIwCAAAAAAAAAA="},6836:(e,n,a)=>{a.d(n,{Z:()=>t});const t="data:image/webp;base64,UklGRowDAABXRUJQVlA4IIADAADQGQCdASp3AGQAPlEgj0UjoiGZKIRUOAUEs6I7kKYHTvL6APLj6HfOp/jd7kd5Y9ADy1faAyHrxb/XOqrXHf2/8kvMr3TP93yS/5f/hfyd1R7/Oaln+8ej5/W/cd7cfnL2C/5X/Sf9b/ZeFA/VVJCh2NOP0ft28zctbfyImCWoKhTBCCaiyT00c4sB/Ri8VmSkTMQZZRRmlnNDuZnh1prW4NeqdmOcIWs2lTrEBYV7bOShzwbUQJImxN+tcLJOSghrzwthqx9Qgk1IjaEiJpvhNJ+xadQNAAD+/cDWcxZH50FUeMtPpJmzGKYIcQ/wKX6KAaMCHZAppIcp8ZKsa837OlRz+i+qSUf8qVP/8kPWG0Ngt/8zxvcOkU4XzOYaB8DZvmvv0oS/ee5gUHL3Kt/XbZ5ZZE9TNS2RuPaQBI7YCmQNL2nHRLRhbt1NxNSDnSeGsHFDFtdH8yt48zvw8fdWdAI+VUfr5fYIsGfX91t0wo4NGhuf4D9fzFyEwOBgD5E+YYh85YrLh5yIP3MJh3RKaPJvfoawzeKZsIZOfnPvS4GbfIaQasoWQXxcN8hQqrntEnyTDyc5+YhBLC+zeXpD2DyK+FeSEEP5VvwePjWNVgiDWHF+zW7oU8QdfEYhsJyb36GsHw5V1SRPzbWWEcve91SQA/BYcnIYRtL/7qfIzUf729hV6osgkbQ+tJjyjcJxkXaHyyGWrC0cEV90qwnji1SL4Rakvny/AtlgjwZVqtx7WC03v+jP2izV0HL0meESkG7AbqD1j9S14U2+OxZBERy3sZL01fi058c9G/+oaUKWJ3832U8JviGBcGgf1DCG+B2cLpjXq8s594foKG5ukjnKQeu7ZMHOV2eEdIQN//KxzV+jjJaDSusvGVBH48hqht2pnFV4toNwJ7YrxDqsC//lYiW3ZQLAaawSLPAbd+sq6YVr1GcOZG2a7baQjufqwFDvAjd/0d88E6QlBZFSOOsL12tXNfb0I+bQnZ4D5Fa53yNOC8zhicIB2z9Hv/f0P00Z1HmYVPqrlzNvzz5F/eqPZx+wDIHw87T3485DV8u6D74179hhkl7dnqjyKs9O2HkfgKroH8Org+BzHX5Z694UJVeUC5l/SDKQ8cgygIOS68Q3RFc0Sv512WV09oGOFMdev6tHlUJqWsZO7L1vi/My971BPC3ZDE4AAAAAAA=="}}]);