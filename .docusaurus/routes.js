import React from 'react';
import ComponentCreator from '@docusaurus/ComponentCreator';

export default [
  {
    path: '/__docusaurus/debug',
    component: ComponentCreator('/__docusaurus/debug', '816'),
    exact: true
  },
  {
    path: '/__docusaurus/debug/config',
    component: ComponentCreator('/__docusaurus/debug/config', 'b66'),
    exact: true
  },
  {
    path: '/__docusaurus/debug/content',
    component: ComponentCreator('/__docusaurus/debug/content', 'f50'),
    exact: true
  },
  {
    path: '/__docusaurus/debug/globalData',
    component: ComponentCreator('/__docusaurus/debug/globalData', '2a0'),
    exact: true
  },
  {
    path: '/__docusaurus/debug/metadata',
    component: ComponentCreator('/__docusaurus/debug/metadata', '5b9'),
    exact: true
  },
  {
    path: '/__docusaurus/debug/registry',
    component: ComponentCreator('/__docusaurus/debug/registry', '964'),
    exact: true
  },
  {
    path: '/__docusaurus/debug/routes',
    component: ComponentCreator('/__docusaurus/debug/routes', 'ac1'),
    exact: true
  },
  {
    path: '/blog',
    component: ComponentCreator('/blog', 'ddd'),
    exact: true
  },
  {
    path: '/blog/archive',
    component: ComponentCreator('/blog/archive', '2ab'),
    exact: true
  },
  {
    path: '/blog/tags',
    component: ComponentCreator('/blog/tags', '12c'),
    exact: true
  },
  {
    path: '/blog/tags/c',
    component: ComponentCreator('/blog/tags/c', '4df'),
    exact: true
  },
  {
    path: '/blog/tags/intro',
    component: ComponentCreator('/blog/tags/intro', '252'),
    exact: true
  },
  {
    path: '/blog/tags/lenguajes',
    component: ComponentCreator('/blog/tags/lenguajes', 'caf'),
    exact: true
  },
  {
    path: '/blog/welcome',
    component: ComponentCreator('/blog/welcome', '4f4'),
    exact: true
  },
  {
    path: '/markdown-page',
    component: ComponentCreator('/markdown-page', 'ca0'),
    exact: true
  },
  {
    path: '/docs',
    component: ComponentCreator('/docs', '99f'),
    routes: [
      {
        path: '/docs/category/01---introducción',
        component: ComponentCreator('/docs/category/01---introducción', '7b3'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/docs/category/02---lenguaje-c',
        component: ComponentCreator('/docs/category/02---lenguaje-c', '2cb'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/docs/intro',
        component: ComponentCreator('/docs/intro', 'aed'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/docs/Introduccion/01.01_programacion_estructurada',
        component: ComponentCreator('/docs/Introduccion/01.01_programacion_estructurada', '278'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/docs/Introduccion/01.02_buenas_practicas',
        component: ComponentCreator('/docs/Introduccion/01.02_buenas_practicas', '0d9'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/docs/Lenguaje C/02.01_conceptos',
        component: ComponentCreator('/docs/Lenguaje C/02.01_conceptos', 'd05'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/docs/Lenguaje C/02.01.E_life_conway',
        component: ComponentCreator('/docs/Lenguaje C/02.01.E_life_conway', '75d'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/docs/Lenguaje C/02.02_estructuras',
        component: ComponentCreator('/docs/Lenguaje C/02.02_estructuras', 'b16'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/docs/Lenguaje C/02.02.E_fractales_julia',
        component: ComponentCreator('/docs/Lenguaje C/02.02.E_fractales_julia', '18c'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/docs/Lenguaje C/02.03_punteros',
        component: ComponentCreator('/docs/Lenguaje C/02.03_punteros', 'dd0'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/docs/Lenguaje C/02.04_repaso',
        component: ComponentCreator('/docs/Lenguaje C/02.04_repaso', 'ff4'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/docs/Lenguaje C/02.05_memoria',
        component: ComponentCreator('/docs/Lenguaje C/02.05_memoria', 'ac7'),
        exact: true,
        sidebar: "tutorialSidebar"
      }
    ]
  },
  {
    path: '/',
    component: ComponentCreator('/', '3b3'),
    exact: true
  },
  {
    path: '*',
    component: ComponentCreator('*'),
  },
];
