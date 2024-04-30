//o que deveria ser aceito e nao foi

// deveria aceitar concatenacao de expressoes
// asl009
//CORRECT
() | int / main {a = (( b * 1) + c) & 1,}
// asl010
//CORRECT
() | int / main {a = (( b * 1) + c) | 1,}

// asl091
//CORRECT
() | int / f {int a, a = 2*(c+k),}
// asl092
//CORRECT
() | int / f {if (a == 2) { },if ((a+b) <= 10) { },}

//OK deveria aceitar {} o vazio nao termina em virgula
// asl016
//CORRECT
() | int / main
{
  if (true) { {}, {}, },
}
// asl017
//CORRECT
() | int / main
{
  if (true) {
     {},
     {},
  },
  if (true) {
    x = 2,
  } else {
    x = 3,
  },
}
// asl037
//CORRECT
() | int / f
{
  if (c)
	 {
	 }else{
  },
}
// asl048
//CORRECT
() | bool / f {}
// asl050
//CORRECT
() | int / f {}
// asl052
//CORRECT
() | float / f
{}
// asl053
//CORRECT
(int a; int b) | int / f
{}
// asl057
//CORRECT
() | int / f
{
  {},
}
// asl058
//CORRECT
() | int / f
{
  {
    {
      {},
    },
  },
}
// asl083
//CORRECT
() | int / f
{
  int c,
  if (c) { },
}
// asl086
//CORRECT
() | int / f
{
  int x,
  int i,
  int j,
  while (i) { },
}


//OK deveria aceitar expressao vazia
// asl073
//CORRECT
() | int / f
{
  f(),
}


