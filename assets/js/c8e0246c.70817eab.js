"use strict";(self.webpackChunklenguajes_estructurados=self.webpackChunklenguajes_estructurados||[]).push([[1829],{3905:(e,n,t)=>{t.d(n,{Zo:()=>u,kt:()=>k});var r=t(7294);function a(e,n,t){return n in e?Object.defineProperty(e,n,{value:t,enumerable:!0,configurable:!0,writable:!0}):e[n]=t,e}function i(e,n){var t=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);n&&(r=r.filter((function(n){return Object.getOwnPropertyDescriptor(e,n).enumerable}))),t.push.apply(t,r)}return t}function l(e){for(var n=1;n<arguments.length;n++){var t=null!=arguments[n]?arguments[n]:{};n%2?i(Object(t),!0).forEach((function(n){a(e,n,t[n])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(t)):i(Object(t)).forEach((function(n){Object.defineProperty(e,n,Object.getOwnPropertyDescriptor(t,n))}))}return e}function o(e,n){if(null==e)return{};var t,r,a=function(e,n){if(null==e)return{};var t,r,a={},i=Object.keys(e);for(r=0;r<i.length;r++)t=i[r],n.indexOf(t)>=0||(a[t]=e[t]);return a}(e,n);if(Object.getOwnPropertySymbols){var i=Object.getOwnPropertySymbols(e);for(r=0;r<i.length;r++)t=i[r],n.indexOf(t)>=0||Object.prototype.propertyIsEnumerable.call(e,t)&&(a[t]=e[t])}return a}var s=r.createContext({}),p=function(e){var n=r.useContext(s),t=n;return e&&(t="function"==typeof e?e(n):l(l({},n),e)),t},u=function(e){var n=p(e.components);return r.createElement(s.Provider,{value:n},e.children)},m="mdxType",c={inlineCode:"code",wrapper:function(e){var n=e.children;return r.createElement(r.Fragment,{},n)}},d=r.forwardRef((function(e,n){var t=e.components,a=e.mdxType,i=e.originalType,s=e.parentName,u=o(e,["components","mdxType","originalType","parentName"]),m=p(t),d=a,k=m["".concat(s,".").concat(d)]||m[d]||c[d]||i;return t?r.createElement(k,l(l({ref:n},u),{},{components:t})):r.createElement(k,l({ref:n},u))}));function k(e,n){var t=arguments,a=n&&n.mdxType;if("string"==typeof e||a){var i=t.length,l=new Array(i);l[0]=d;var o={};for(var s in n)hasOwnProperty.call(n,s)&&(o[s]=n[s]);o.originalType=e,o[m]="string"==typeof e?e:a,l[1]=o;for(var p=2;p<i;p++)l[p]=t[p];return r.createElement.apply(null,l)}return r.createElement.apply(null,t)}d.displayName="MDXCreateElement"},3252:(e,n,t)=>{t.r(n),t.d(n,{assets:()=>s,contentTitle:()=>l,default:()=>c,frontMatter:()=>i,metadata:()=>o,toc:()=>p});var r=t(7462),a=(t(7294),t(3905));const i={marp:!0,theme:"default",size:969,paginate:!0},l="Relaci\xf3n entre matrices y punteros",o={unversionedId:"Lenguaje C/Punteros/punteros_y_matrices",id:"Lenguaje C/Punteros/punteros_y_matrices",title:"Relaci\xf3n entre matrices y punteros",description:"Lenguajes Estructurados",source:"@site/docs/02 - Lenguaje C/Punteros/2.punteros_y_matrices.md",sourceDirName:"02 - Lenguaje C/Punteros",slug:"/Lenguaje C/Punteros/punteros_y_matrices",permalink:"/lenguajes-estructurados/docs/Lenguaje C/Punteros/punteros_y_matrices",draft:!1,editUrl:"https://github.com/abelranni/lenguajes-estructurados/tree/main/docs/02 - Lenguaje C/Punteros/2.punteros_y_matrices.md",tags:[],version:"current",sidebarPosition:2,frontMatter:{marp:!0,theme:"default",size:969,paginate:!0},sidebar:"tutorialSidebar",previous:{title:"Punteros en C",permalink:"/lenguajes-estructurados/docs/Lenguaje C/Punteros/punteros"},next:{title:"03 - Ejercicios Resueltos",permalink:"/lenguajes-estructurados/docs/category/03---ejercicios-resueltos"}},s={},p=[{value:"Lenguajes Estructurados",id:"lenguajes-estructurados",level:2},{value:"Ejemplo 1: Punteros y matrices",id:"ejemplo-1-punteros-y-matrices",level:3},{value:"Ejemplo 2: Matrices y punteros",id:"ejemplo-2-matrices-y-punteros",level:3}],u={toc:p},m="wrapper";function c(e){let{components:n,...i}=e;return(0,a.kt)(m,(0,r.Z)({},u,i,{components:n,mdxType:"MDXLayout"}),(0,a.kt)("h1",{id:"relaci\xf3n-entre-matrices-y-punteros"},"Relaci\xf3n entre matrices y punteros"),(0,a.kt)("h2",{id:"lenguajes-estructurados"},"Lenguajes Estructurados"),(0,a.kt)("hr",null),(0,a.kt)("p",null,"Una matriz es un bloque de datos secuenciales. Vamos a escribir un programa para imprimir direcciones de elementos de matriz."),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre",className:"language-c"},'#include <stdio.h>\nint main() {\n   int x[4];\n   int i;\n\n   for(i = 0; i < 4; ++i) {\n      printf("&x[%d] = %p\\n", i, &x[i]);\n   }\n\n   printf("Direccion del array x: %p", x);\n\n   return 0;\n}\n')),(0,a.kt)("hr",null),(0,a.kt)("p",null,(0,a.kt)("strong",{parentName:"p"},"Salida")),(0,a.kt)("p",null,"&x","[0]"," = 1450734448\n&x","[1]"," = 1450734452\n&x","[2]"," = 1450734456\n&x","[3]"," = 1450734460\nDireccion del array x: 1450734448"),(0,a.kt)("p",null,"Hay una diferencia de 4 bytes entre dos elementos consecutivos de la matriz ",(0,a.kt)("inlineCode",{parentName:"p"},"x"),". Es porque el tama\xf1o de ",(0,a.kt)("inlineCode",{parentName:"p"},"int")," es de 4 bytes (en nuestro compilador)."),(0,a.kt)("p",null,"Por lo tanto, la direcci\xf3n de ",(0,a.kt)("inlineCode",{parentName:"p"},"x[1]")," es ",(0,a.kt)("inlineCode",{parentName:"p"},"4")," bytes m\xe1s que la direcci\xf3n de ",(0,a.kt)("inlineCode",{parentName:"p"},"x[0]"),". De manera similar, la direcci\xf3n de ",(0,a.kt)("inlineCode",{parentName:"p"},"x[2]")," es ",(0,a.kt)("inlineCode",{parentName:"p"},"4")," bytes m\xe1s que la direcci\xf3n de ",(0,a.kt)("inlineCode",{parentName:"p"},"x[1]")," y as\xed sucesivamente."),(0,a.kt)("p",null,"Tener en cuenta que, la direcci\xf3n de ",(0,a.kt)("inlineCode",{parentName:"p"},"&x[0]")," y ",(0,a.kt)("inlineCode",{parentName:"p"},"x")," es lo mismo. Es porque el nombre de la variable apunta al primer elemento de la matriz."),(0,a.kt)("hr",null),(0,a.kt)("p",null,(0,a.kt)("img",{alt:"Relaci\xf3n entre matrices y punteros",src:t(4716).Z,title:"Arrays as Pointers",width:"263",height:"73"})),(0,a.kt)("p",null,"Del ejemplo anterior, queda claro que ",(0,a.kt)("inlineCode",{parentName:"p"},"&x[0]")," es equivalente a ",(0,a.kt)("inlineCode",{parentName:"p"},"x"),". Y, ",(0,a.kt)("inlineCode",{parentName:"p"},"x[0]")," es equivalente a ",(0,a.kt)("inlineCode",{parentName:"p"},"*x"),"."),(0,a.kt)("p",null,"Semejantemente"),(0,a.kt)("ul",null,(0,a.kt)("li",{parentName:"ul"},(0,a.kt)("inlineCode",{parentName:"li"},"&x[1]"),"\xa0es equivalente a ",(0,a.kt)("inlineCode",{parentName:"li"},"x+1")," y ",(0,a.kt)("inlineCode",{parentName:"li"},"x[1]")," es equivalente a ",(0,a.kt)("inlineCode",{parentName:"li"},"*(x+1)")),(0,a.kt)("li",{parentName:"ul"},(0,a.kt)("inlineCode",{parentName:"li"},"&x[2]"),"\xa0es equivalente a ",(0,a.kt)("inlineCode",{parentName:"li"},"x+2")," y ",(0,a.kt)("inlineCode",{parentName:"li"},"x[2]")," es equivalente a ",(0,a.kt)("inlineCode",{parentName:"li"},"*(x+2)")),(0,a.kt)("li",{parentName:"ul"},"..."),(0,a.kt)("li",{parentName:"ul"},"B\xe1sicamente, ",(0,a.kt)("inlineCode",{parentName:"li"},"&x[i]")," es equivalente a ",(0,a.kt)("inlineCode",{parentName:"li"},"x+i")," y ",(0,a.kt)("inlineCode",{parentName:"li"},"x[i]")," es equivalente a ",(0,a.kt)("inlineCode",{parentName:"li"},"*(x+i)"),".")),(0,a.kt)("hr",null),(0,a.kt)("h3",{id:"ejemplo-1-punteros-y-matrices"},"Ejemplo 1: Punteros y matrices"),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre",className:"language-c"},'#include <stdio.h>\nint main() {\n\n  int i, x[6], sum = 0;\n\n  printf("Enter 6 numbers: ");\n\n  for(i = 0; i < 6; ++i) {\n  // Equivalente a scanf("%d", &x[i]);\n      scanf("%d", x+i);\n\n  // Equivalente a sum += x[i]\n      sum += *(x+i);\n  }\n\n  printf("Sum = %d", sum);\n\n  return 0;\n}\n')),(0,a.kt)("hr",null),(0,a.kt)("p",null,"Cuando ejecute el programa, el resultado ser\xe1:"),(0,a.kt)("p",null,"Enter 6 numbers: 2"),(0,a.kt)("p",null,"3\n4\n4\n12\n4\nSum = 29"),(0,a.kt)("p",null,"Aqu\xed, hemos declarado una matriz ",(0,a.kt)("inlineCode",{parentName:"p"},"x")," de 6 elementos. Para acceder a los elementos de la matriz, hemos utilizado punteros."),(0,a.kt)("hr",null),(0,a.kt)("p",null,"En la mayor\xeda de los contextos, los nombres de matriz se descomponen en punteros."),(0,a.kt)("p",null,"En palabras simples, los nombres de matriz se convierten en punteros."),(0,a.kt)("p",null,"Esa es la raz\xf3n por la que puede usar punteros para acceder a elementos de matrices."),(0,a.kt)("p",null,"Sin embargo, debe recordar que los punteros y las matrices no son lo mismo."),(0,a.kt)("hr",null),(0,a.kt)("h3",{id:"ejemplo-2-matrices-y-punteros"},"Ejemplo 2: Matrices y punteros"),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre",className:"language-c"},'#include <stdio.h>\nint main() {\n\n  int x[5] = {1, 2, 3, 4, 5};\n  int* ptr;\n\n  // a ptr se le asigna la direcci\xf3n del tercer elemento\n  ptr = &x[2]; \n\n  printf("*ptr = %d \\n", *ptr);           // 3\n  printf("*(ptr+1) = %d \\n", *(ptr+1));   // 4\n  printf("*(ptr-1) = %d", *(ptr-1));      // 2\n\n  return 0;\n}\n')),(0,a.kt)("hr",null),(0,a.kt)("p",null,"Cuando ejecute el programa, el resultado ser\xe1:"),(0,a.kt)("p",null,(0,a.kt)("em",{parentName:"p"},"ptr = 3\n"),"(ptr+1) = 4\n*(ptr-1) = 2"),(0,a.kt)("p",null,"En este ejemplo, ",(0,a.kt)("inlineCode",{parentName:"p"},"&x[2]"),", la direcci\xf3n del tercer elemento se asigna al puntero ",(0,a.kt)("inlineCode",{parentName:"p"},"ptr"),". Por lo tanto,",(0,a.kt)("inlineCode",{parentName:"p"},"3")," se mostr\xf3 cuando imprimimos ",(0,a.kt)("inlineCode",{parentName:"p"},"*ptr"),"."),(0,a.kt)("p",null,"La impresi\xf3n de ",(0,a.kt)("inlineCode",{parentName:"p"},"*(ptr+1)")," nos da el cuarto elemento. Del mismo modo, la impresi\xf3n de ",(0,a.kt)("inlineCode",{parentName:"p"},"*(ptr-1)")," nos da el segundo elemento."))}c.isMDXComponent=!0},4716:(e,n,t)=>{t.d(n,{Z:()=>r});const r="data:image/webp;base64,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"}}]);