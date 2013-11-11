Escola de Conducao
==================
1.º Trabalho de Grupo de AEDA, FEUP

AEDA1314_2MIEIC5_C

Requisitos Obrigatórios:
------------------------
- [x] Manutenção de viaturas
- [x] Manutenção de instrutores
- [x] Manutenção de alunos
- [x] Manutenção de aulas
- [x] Associar aulas a alunos
- [x] Associar aulas a instrutores
- [x] Associar aulas a viaturas
- [..] Distribuir alunos de instrutor removido
- [..] Controlar marcação de aulas

---

File Syntax
===========

Main file:
----------
= Dados dos Veiculos =
> n

> matricula anoFabrico marca tipo dataUltimaInspec periodicidadeInspec

= Dados dos Instrutores =
> n

> nome qualifLig qualifPes qualifMoto

= Dados dos Alunos =
> n

> nome tipoCarta matriculaViaturaUsual

Lessons file:
-------------
= Horario da Escola =
> abertura fecho

= Dados das Aulas =
> n

> data hora duracao aluno instrutor matriculaViaturaUsual