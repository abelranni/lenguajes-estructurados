"use strict";(self.webpackChunklenguajes_estructurados=self.webpackChunklenguajes_estructurados||[]).push([[9351],{3905:(e,n,a)=>{a.d(n,{Zo:()=>u,kt:()=>k});var r=a(7294);function i(e,n,a){return n in e?Object.defineProperty(e,n,{value:a,enumerable:!0,configurable:!0,writable:!0}):e[n]=a,e}function t(e,n){var a=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);n&&(r=r.filter((function(n){return Object.getOwnPropertyDescriptor(e,n).enumerable}))),a.push.apply(a,r)}return a}function l(e){for(var n=1;n<arguments.length;n++){var a=null!=arguments[n]?arguments[n]:{};n%2?t(Object(a),!0).forEach((function(n){i(e,n,a[n])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(a)):t(Object(a)).forEach((function(n){Object.defineProperty(e,n,Object.getOwnPropertyDescriptor(a,n))}))}return e}function o(e,n){if(null==e)return{};var a,r,i=function(e,n){if(null==e)return{};var a,r,i={},t=Object.keys(e);for(r=0;r<t.length;r++)a=t[r],n.indexOf(a)>=0||(i[a]=e[a]);return i}(e,n);if(Object.getOwnPropertySymbols){var t=Object.getOwnPropertySymbols(e);for(r=0;r<t.length;r++)a=t[r],n.indexOf(a)>=0||Object.prototype.propertyIsEnumerable.call(e,a)&&(i[a]=e[a])}return i}var c=r.createContext({}),s=function(e){var n=r.useContext(c),a=n;return e&&(a="function"==typeof e?e(n):l(l({},n),e)),a},u=function(e){var n=s(e.components);return r.createElement(c.Provider,{value:n},e.children)},d="mdxType",p={inlineCode:"code",wrapper:function(e){var n=e.children;return r.createElement(r.Fragment,{},n)}},m=r.forwardRef((function(e,n){var a=e.components,i=e.mdxType,t=e.originalType,c=e.parentName,u=o(e,["components","mdxType","originalType","parentName"]),d=s(a),m=i,k=d["".concat(c,".").concat(m)]||d[m]||p[m]||t;return a?r.createElement(k,l(l({ref:n},u),{},{components:a})):r.createElement(k,l({ref:n},u))}));function k(e,n){var a=arguments,i=n&&n.mdxType;if("string"==typeof e||i){var t=a.length,l=new Array(t);l[0]=m;var o={};for(var c in n)hasOwnProperty.call(n,c)&&(o[c]=n[c]);o.originalType=e,o[d]="string"==typeof e?e:i,l[1]=o;for(var s=2;s<t;s++)l[s]=a[s];return r.createElement.apply(null,l)}return r.createElement.apply(null,a)}m.displayName="MDXCreateElement"},5257:(e,n,a)=>{a.r(n),a.d(n,{assets:()=>c,contentTitle:()=>l,default:()=>p,frontMatter:()=>t,metadata:()=>o,toc:()=>s});var r=a(7462),i=(a(7294),a(3905));const t={marp:!0,theme:"default",size:969,paginate:!0},l="03.03.A - Juego de Snake en C",o={unversionedId:"Ejercicios Resueltos/03.03.A_snake",id:"Ejercicios Resueltos/03.03.A_snake",title:"03.03.A - Juego de Snake en C",description:"Lenguajes Estructurados",source:"@site/docs/03 - Ejercicios Resueltos/03.03.A_snake.md",sourceDirName:"03 - Ejercicios Resueltos",slug:"/Ejercicios Resueltos/03.03.A_snake",permalink:"/lenguajes-estructurados/docs/Ejercicios Resueltos/03.03.A_snake",draft:!1,editUrl:"https://github.com/abelranni/lenguajes-estructurados/tree/main/docs/03 - Ejercicios Resueltos/03.03.A_snake.md",tags:[],version:"current",frontMatter:{marp:!0,theme:"default",size:969,paginate:!0},sidebar:"tutorialSidebar",previous:{title:"03.02 - Fractales de Julia",permalink:"/lenguajes-estructurados/docs/Ejercicios Resueltos/03.02_fractales_julia"},next:{title:"03.03.B - Snake en Python",permalink:"/lenguajes-estructurados/docs/Ejercicios Resueltos/03.03.B_snake_py"}},c={},s=[{value:"Lenguajes Estructurados",id:"lenguajes-estructurados",level:2},{value:"\xbfQu\xe9 es Snake?",id:"qu\xe9-es-snake",level:2},{value:"Objetivo del ejercicio",id:"objetivo-del-ejercicio",level:2},{value:"Descripci\xf3n",id:"descripci\xf3n",level:3},{value:"Evaluaci\xf3n",id:"evaluaci\xf3n",level:2},{value:"Implementaci\xf3n del juego SNAKE en C utilizando SDL2",id:"implementaci\xf3n-del-juego-snake-en-c-utilizando-sdl2",level:2},{value:"Estructuras de datos",id:"estructuras-de-datos",level:2},{value:"Coordenadas",id:"coordenadas",level:3},{value:"Serpiente",id:"serpiente",level:3},{value:"Funciones",id:"funciones",level:2},{value:"inicializar_serpiente",id:"inicializar_serpiente",level:3},{value:"mover_serpiente",id:"mover_serpiente",level:3},{value:"colision",id:"colision",level:3},{value:"comer",id:"comer",level:3},{value:"generar_comida",id:"generar_comida",level:3},{value:"dibujar_serpiente",id:"dibujar_serpiente",level:3},{value:"dibujar_comida",id:"dibujar_comida",level:3},{value:"manejar_eventos",id:"manejar_eventos",level:3},{value:"Programa principal",id:"programa-principal",level:3}],u={toc:s},d="wrapper";function p(e){let{components:n,...a}=e;return(0,i.kt)(d,(0,r.Z)({},u,a,{components:n,mdxType:"MDXLayout"}),(0,i.kt)("h1",{id:"0303a---juego-de-snake-en-c"},"03.03.A - Juego de Snake en C"),(0,i.kt)("h2",{id:"lenguajes-estructurados"},"Lenguajes Estructurados"),(0,i.kt)("hr",null),(0,i.kt)("h2",{id:"qu\xe9-es-snake"},"\xbfQu\xe9 es Snake?"),(0,i.kt)("ul",null,(0,i.kt)("li",{parentName:"ul"},"Es un videojuego lanzado a mediados de la d\xe9cada de 1970 que ha mantenido su popularidad desde entonces, convirti\xe9ndose en un cl\xe1sico. "),(0,i.kt)("li",{parentName:"ul"},"En 1998, el Snake obtuvo una audiencia masiva tras convertirse en un juego est\xe1ndar pre-grabado en los tel\xe9fonos Nokia."),(0,i.kt)("li",{parentName:"ul"},"El objetivo del juego es guiar una serpiente por un \xe1rea rectangular, recogiendo comida, evitando chocar con las paredes o con su propio cuerpo."),(0,i.kt)("li",{parentName:"ul"},"Cada vez que la serpiente come una pieza de comida, su cuerpo crece un segmento, lo que hace que el juego sea cada vez m\xe1s dif\xedcil."),(0,i.kt)("li",{parentName:"ul"},"El juego termina cuando la serpiente choca con la pared o con su propio cuerpo.")),(0,i.kt)("hr",null),(0,i.kt)("h2",{id:"objetivo-del-ejercicio"},"Objetivo del ejercicio"),(0,i.kt)("p",null,"Crear un programa en C que simule un tablero de juego de Snake utilizando punteros, programaci\xf3n estructurada y la librer\xeda SDL para la representaci\xf3n gr\xe1fica."),(0,i.kt)("h3",{id:"descripci\xf3n"},"Descripci\xf3n"),(0,i.kt)("p",null,"El programa deber\xe1 cumplir con los siguientes requisitos:"),(0,i.kt)("ul",null,(0,i.kt)("li",{parentName:"ul"},"Utilizar una estructura para representar las coordenadas (x, y) en el tablero")),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"typedef struct {\n    int x;\n    int y;\n} Coordenada;\n\n")),(0,i.kt)("hr",null),(0,i.kt)("ul",null,(0,i.kt)("li",{parentName:"ul"},"Utilizar una estructura para representar la serpiente, que incluya un puntero a un arreglo din\xe1mico de coordenadas y un entero que indique el tama\xf1o de la serpiente")),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"typedef struct {\n    Coordenada* cuerpo;\n    int longitud;\n} Serpiente;\n\n")),(0,i.kt)("hr",null),(0,i.kt)("ul",null,(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("p",{parentName:"li"},"Implementar las siguientes funciones:"),(0,i.kt)("ul",{parentName:"li"},(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("inlineCode",{parentName:"li"},"Serpiente* crear_serpiente(int longitud_inicial)")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("inlineCode",{parentName:"li"},"void destruir_serpiente(Serpiente* serpiente)")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("inlineCode",{parentName:"li"},"void mover_serpiente(Serpiente* serpiente, int direccion)")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("inlineCode",{parentName:"li"},"int colision(Serpiente* serpiente)")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("inlineCode",{parentName:"li"},"int comer(Serpiente* serpiente, Coordenada comida)"))))),(0,i.kt)("hr",null),(0,i.kt)("ul",null,(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("p",{parentName:"li"},"Utilizar punteros y programaci\xf3n estructurada en todas las funciones.")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("p",{parentName:"li"},"Inicializar y configurar SDL para la representaci\xf3n gr\xe1fica del juego, con un tama\xf1o de ventana adecuado y una representaci\xf3n simple de los elementos del juego (serpiente, comida).")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("p",{parentName:"li"},"Crear un bucle principal que maneje la l\xf3gica del juego (mover serpiente, detectar colisiones, generar comida, etc.) y actualice la pantalla utilizando SDL.")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("p",{parentName:"li"},"Controlar la velocidad del juego ajustando el tiempo de espera en cada iteraci\xf3n del bucle principal."))),(0,i.kt)("hr",null),(0,i.kt)("h2",{id:"evaluaci\xf3n"},"Evaluaci\xf3n"),(0,i.kt)("p",null,"Se valorar\xe1 la eficiencia y organizaci\xf3n del c\xf3digo, as\xed como la correcta gesti\xf3n de memoria din\xe1mica."),(0,i.kt)("hr",null),(0,i.kt)("h2",{id:"implementaci\xf3n-del-juego-snake-en-c-utilizando-sdl2"},"Implementaci\xf3n del juego SNAKE en C utilizando SDL2"),(0,i.kt)("p",null,"Este programa implementa una versi\xf3n simple del juego de la serpiente en C utilizando la biblioteca SDL2 para gr\xe1ficos."),(0,i.kt)("h2",{id:"estructuras-de-datos"},"Estructuras de datos"),(0,i.kt)("h3",{id:"coordenadas"},"Coordenadas"),(0,i.kt)("p",null,"Esta estructura representa las coordenadas ",(0,i.kt)("inlineCode",{parentName:"p"},"x")," e ",(0,i.kt)("inlineCode",{parentName:"p"},"y")," en el \xe1rea de juego."),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"typedef struct {\n    int x;\n    int y;\n} Coordenadas;    \n")),(0,i.kt)("hr",null),(0,i.kt)("h3",{id:"serpiente"},"Serpiente"),(0,i.kt)("p",null,"Esta estructura representa la serpiente en el juego, incluyendo su longitud y las coordenadas de cada parte de su cuerpo."),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"typedef struct\n{\n    Coordenada *cuerpo;\n    int longitud;\n} Serpiente;\n")),(0,i.kt)("hr",null),(0,i.kt)("h2",{id:"funciones"},"Funciones"),(0,i.kt)("h3",{id:"inicializar_serpiente"},"inicializar_serpiente"),(0,i.kt)("p",null,"Esta funci\xf3n inicializa la serpiente, estableciendo su longitud. Inicialmente su cuerpo estar\xe1 formado por una \xfanica coordenada en el centro del \xe1rea de juego."),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"Serpiente *crear_serpiente(int longitud_inicial)\n{\n    Serpiente *serpiente = (Serpiente *)malloc(sizeof(Serpiente));\n    serpiente->longitud = longitud_inicial;\n    serpiente->cuerpo = (Coordenada *)malloc(longitud_inicial * sizeof(Coordenada));\n    for (int i = 0; i < longitud_inicial; i++)\n    {\n        serpiente->cuerpo[i].x = i + 1;\n        serpiente->cuerpo[i].y = 1;\n    }\n    return serpiente;\n}\n")),(0,i.kt)("hr",null),(0,i.kt)("h3",{id:"mover_serpiente"},"mover_serpiente"),(0,i.kt)("p",null,"Esta funci\xf3n actualiza la posici\xf3n de la serpiente seg\xfan la direcci\xf3n dada."),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"void mover_serpiente(Serpiente* serpiente, int direccion) {\n    // ...\n}\n")),(0,i.kt)("hr",null),(0,i.kt)("h3",{id:"colision"},"colision"),(0,i.kt)("p",null,"Esta funci\xf3n verifica si la serpiente colisiona con los l\xedmites del \xe1rea de juego o consigo misma."),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"int colision(Serpiente* serpiente, int ancho, int alto) {\n    // ...\n}\n")),(0,i.kt)("hr",null),(0,i.kt)("h3",{id:"comer"},"comer"),(0,i.kt)("p",null,"Esta funci\xf3n verifica si la serpiente come la comida y, en caso afirmativo, incrementa su longitud."),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"int comer(Serpiente* serpiente, Coordenadas comida) {\n    // ...\n}\n")),(0,i.kt)("hr",null),(0,i.kt)("h3",{id:"generar_comida"},"generar_comida"),(0,i.kt)("p",null,"Esta funci\xf3n genera una nueva posici\xf3n de comida en el \xe1rea de juego, asegur\xe1ndose de que no aparezca dentro del cuerpo de la serpiente."),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"Coordenada generar_comida(Serpiente* serpiente, int ancho, int alto) {\n    // ...\n}\n")),(0,i.kt)("hr",null),(0,i.kt)("h3",{id:"dibujar_serpiente"},"dibujar_serpiente"),(0,i.kt)("p",null,"Esta funci\xf3n dibuja la serpiente en el \xe1rea de juego utilizando el renderizador SDL."),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"void dibujar_serpiente(SDL_Renderer *renderer, Serpiente *serpiente, int size_celda)\n{\n    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);\n    SDL_Rect rect;\n    rect.w = size_celda;\n    rect.h = size_celda;\n\n    for (int i = 0; i < serpiente->longitud; i++)\n    {\n        rect.x = serpiente->cuerpo[i].x * size_celda;\n        rect.y = serpiente->cuerpo[i].y * size_celda;\n        SDL_RenderFillRect(renderer, &rect);\n    }\n}\n")),(0,i.kt)("hr",null),(0,i.kt)("h3",{id:"dibujar_comida"},"dibujar_comida"),(0,i.kt)("p",null,"Esta funci\xf3n dibuja la comida en el \xe1rea de juego utilizando el renderizador SDL."),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"void dibujar_comida(SDL_Renderer* renderer, Coordenada comida, int size_celda) {\n    // ...\n}\n")),(0,i.kt)("hr",null),(0,i.kt)("h3",{id:"manejar_eventos"},"manejar_eventos"),(0,i.kt)("p",null,"Esta funci\xf3n maneja los eventos de SDL y actualiza las variables salir, iniciar_movimiento y direccion."),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"void manejar_eventos(int *salir, int *iniciar_movimiento, int *direccion)\n{\n    SDL_Event evento;\n    while (SDL_PollEvent(&evento))\n    {\n        switch (evento.type)\n        {\n\n        case SDL_QUIT:\n            *salir = 1;\n            break;\n")),(0,i.kt)("hr",null),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"        case SDL_KEYDOWN:\n\n            switch (evento.key.keysym.scancode)\n            {\n            case SDL_SCANCODE_UP:\n                if (*direccion != 2)\n                {\n                    *direccion = 0;\n                    *iniciar_movimiento = 1;\n                }\n                break;\n            case SDL_SCANCODE_RIGHT:\n                if (*direccion != 3)\n                {\n                    *direccion = 1;\n                    *iniciar_movimiento = 1;\n                }\n                break;\n\n")),(0,i.kt)("hr",null),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},"            case SDL_SCANCODE_DOWN:\n                if (*direccion != 0)\n                {\n                    *direccion = 2;\n                    *iniciar_movimiento = 1;\n                }\n                break;\n            case SDL_SCANCODE_LEFT:\n                if (*direccion != 1)\n                {\n                    *direccion = 3;\n                    *iniciar_movimiento = 1;\n                }\n                break;\n            }\n        }\n    }\n}\n\n")),(0,i.kt)("hr",null),(0,i.kt)("h3",{id:"programa-principal"},"Programa principal"),(0,i.kt)("p",null,"El programa principal inicializa SDL y crea una ventana y un renderizador. Luego, inicializa la serpiente y la comida, y entra en un bucle principal que maneja los eventos, actualiza la posici\xf3n de la serpiente, verifica las colisiones y la comida, y dibuja la serpiente y la comida en la ventana."),(0,i.kt)("hr",null),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},'int WinMain(int argc, char *argv[])\n{\n    srand(time(NULL));\n    int ancho = 20;\n    int alto = 15;\n    int size_celda = 32;\n    int velocidad = 100;\n\n    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {\n        printf("error initializing SDL: %s\\n", SDL_GetError());\n    }\n\n    SDL_Window *window = SDL_CreateWindow("Snake", \n                                           SDL_WINDOWPOS_CENTERED, \n                                           SDL_WINDOWPOS_CENTERED, \n                                           ancho * size_celda,  \n                                           alto * size_celda, 0);\n\n    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);\n\n    Serpiente *serpiente = crear_serpiente(3);\n    Coordenada comida = generar_comida(serpiente, ancho, alto);\n\n    int direccion = 1; // Inicializamos la direcci\xf3n en -1 (ninguna direcci\xf3n)\n    int iniciar_movimiento = 0 ;\n    int salir = 0;\n')),(0,i.kt)("hr",null),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},'    while (!salir)\n    {\n        manejar_eventos(&salir, &iniciar_movimiento, &direccion);\n\n        if (iniciar_movimiento)\n        {\n            mover_serpiente(serpiente, direccion);\n\n            if (colision(serpiente, ancho, alto))\n            {\n                printf("Colision \\n");\n                while (!salir)\n                {\n                    SDL_Event evento;\n                    while (SDL_PollEvent(&evento))\n                    {\n                        if (evento.type == SDL_QUIT)\n                        {\n                            salir = 1;\n                        }\n                    }\n                    SDL_Delay(100);\n                }\n            }\n')),(0,i.kt)("hr",null),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-c"},'\n            if (comer(serpiente, comida))\n            {\n                printf("Comer \\n");\n                comida = generar_comida(serpiente, ancho, alto);\n            }\n        }\n\n        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);\n\n        SDL_RenderClear(renderer);\n\n        dibujar_serpiente(renderer, serpiente, size_celda);\n\n        dibujar_comida(renderer, comida, size_celda);\n\n        SDL_RenderPresent(renderer);\n\n        SDL_Delay(velocidad);\n    }\n\n    destruir_serpiente(serpiente);\n    SDL_DestroyRenderer(renderer);\n    SDL_DestroyWindow(window);\n    SDL_Quit();\n\n    return 0;\n')),(0,i.kt)("hr",null))}p.isMDXComponent=!0}}]);