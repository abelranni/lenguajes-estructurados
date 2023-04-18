import React from 'react';
import ComponentCreator from '@docusaurus/ComponentCreator';

export default [
  {
    path: '/lenguajes-estructurados/__docusaurus/debug',
    component: ComponentCreator('/lenguajes-estructurados/__docusaurus/debug', 'a31'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/__docusaurus/debug/config',
    component: ComponentCreator('/lenguajes-estructurados/__docusaurus/debug/config', '4f5'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/__docusaurus/debug/content',
    component: ComponentCreator('/lenguajes-estructurados/__docusaurus/debug/content', 'a69'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/__docusaurus/debug/globalData',
    component: ComponentCreator('/lenguajes-estructurados/__docusaurus/debug/globalData', '390'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/__docusaurus/debug/metadata',
    component: ComponentCreator('/lenguajes-estructurados/__docusaurus/debug/metadata', '9ee'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/__docusaurus/debug/registry',
    component: ComponentCreator('/lenguajes-estructurados/__docusaurus/debug/registry', 'cca'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/__docusaurus/debug/routes',
    component: ComponentCreator('/lenguajes-estructurados/__docusaurus/debug/routes', '070'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/blog',
    component: ComponentCreator('/lenguajes-estructurados/blog', '304'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/blog/archive',
    component: ComponentCreator('/lenguajes-estructurados/blog/archive', '239'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/blog/tags',
    component: ComponentCreator('/lenguajes-estructurados/blog/tags', 'c10'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/blog/tags/c',
    component: ComponentCreator('/lenguajes-estructurados/blog/tags/c', '248'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/blog/tags/intro',
    component: ComponentCreator('/lenguajes-estructurados/blog/tags/intro', 'e40'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/blog/tags/lenguajes',
    component: ComponentCreator('/lenguajes-estructurados/blog/tags/lenguajes', 'f02'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/blog/welcome',
    component: ComponentCreator('/lenguajes-estructurados/blog/welcome', '931'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/markdown-page',
    component: ComponentCreator('/lenguajes-estructurados/markdown-page', 'd31'),
    exact: true
  },
  {
    path: '/lenguajes-estructurados/docs',
    component: ComponentCreator('/lenguajes-estructurados/docs', 'f46'),
    routes: [
      {
        path: '/lenguajes-estructurados/docs/category/00---configuración',
        component: ComponentCreator('/lenguajes-estructurados/docs/category/00---configuración', 'cc3'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/category/01---introducción',
        component: ComponentCreator('/lenguajes-estructurados/docs/category/01---introducción', 'e21'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/category/02---lenguaje-c',
        component: ComponentCreator('/lenguajes-estructurados/docs/category/02---lenguaje-c', 'e85'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/category/03---ejercicios-resueltos',
        component: ComponentCreator('/lenguajes-estructurados/docs/category/03---ejercicios-resueltos', '1e9'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Configuraciones/00.01_config_vscode_mingw',
        component: ComponentCreator('/lenguajes-estructurados/docs/Configuraciones/00.01_config_vscode_mingw', '772'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Configuraciones/00.02_library_SDL2',
        component: ComponentCreator('/lenguajes-estructurados/docs/Configuraciones/00.02_library_SDL2', '70c'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Ejercicios Resueltos/03.01_life_conway',
        component: ComponentCreator('/lenguajes-estructurados/docs/Ejercicios Resueltos/03.01_life_conway', 'ce1'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Ejercicios Resueltos/03.02_fractales_julia',
        component: ComponentCreator('/lenguajes-estructurados/docs/Ejercicios Resueltos/03.02_fractales_julia', 'fae'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Ejercicios Resueltos/03.03.A_snake',
        component: ComponentCreator('/lenguajes-estructurados/docs/Ejercicios Resueltos/03.03.A_snake', 'c6e'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Ejercicios Resueltos/03.03.B_snake_py',
        component: ComponentCreator('/lenguajes-estructurados/docs/Ejercicios Resueltos/03.03.B_snake_py', '823'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Ejercicios Resueltos/03.05_tictactoe',
        component: ComponentCreator('/lenguajes-estructurados/docs/Ejercicios Resueltos/03.05_tictactoe', 'fed'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/intro',
        component: ComponentCreator('/lenguajes-estructurados/docs/intro', 'e89'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Introduccion/01.01_programacion_estructurada',
        component: ComponentCreator('/lenguajes-estructurados/docs/Introduccion/01.01_programacion_estructurada', '8ff'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Introduccion/01.02_buenas_practicas',
        component: ComponentCreator('/lenguajes-estructurados/docs/Introduccion/01.02_buenas_practicas', '61c'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Introduccion/01.03_dry_etc',
        component: ComponentCreator('/lenguajes-estructurados/docs/Introduccion/01.03_dry_etc', '8bf'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Lenguaje C/02.01_conceptos',
        component: ComponentCreator('/lenguajes-estructurados/docs/Lenguaje C/02.01_conceptos', '120'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Lenguaje C/02.02_estructuras',
        component: ComponentCreator('/lenguajes-estructurados/docs/Lenguaje C/02.02_estructuras', 'e45'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Lenguaje C/02.03_punteros',
        component: ComponentCreator('/lenguajes-estructurados/docs/Lenguaje C/02.03_punteros', 'e9b'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Lenguaje C/02.04_repaso',
        component: ComponentCreator('/lenguajes-estructurados/docs/Lenguaje C/02.04_repaso', 'c37'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Lenguaje C/02.05_memoria',
        component: ComponentCreator('/lenguajes-estructurados/docs/Lenguaje C/02.05_memoria', 'ce2'),
        exact: true,
        sidebar: "tutorialSidebar"
      }
    ]
  },
  {
    path: '/lenguajes-estructurados/',
    component: ComponentCreator('/lenguajes-estructurados/', 'ccf'),
    exact: true
  },
  {
    path: '*',
    component: ComponentCreator('*'),
  },
];
