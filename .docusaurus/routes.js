import React from 'react';
import ComponentCreator from '@docusaurus/ComponentCreator';

export default [
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
    component: ComponentCreator('/lenguajes-estructurados/docs', '007'),
    routes: [
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
        path: '/lenguajes-estructurados/docs/Lenguaje C/02.01_conceptos',
        component: ComponentCreator('/lenguajes-estructurados/docs/Lenguaje C/02.01_conceptos', '120'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/lenguajes-estructurados/docs/Lenguaje C/02.01.E_life_conway',
        component: ComponentCreator('/lenguajes-estructurados/docs/Lenguaje C/02.01.E_life_conway', 'e2d'),
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
        path: '/lenguajes-estructurados/docs/Lenguaje C/02.02.E_fractales_julia',
        component: ComponentCreator('/lenguajes-estructurados/docs/Lenguaje C/02.02.E_fractales_julia', '208'),
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
