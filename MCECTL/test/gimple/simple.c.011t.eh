
;; Function int main(int, char**) (main)

int main(int, char**) (int argc, char * * argv)
{
  int D.2215;
  int result;
  int D.2213;

  D.2215 = hello ();
  result = D.2215;
  D.2213 = result;
  goto <D.2214>;
  D.2213 = 0;
  goto <D.2214>;
  <D.2214>:
  return D.2213;
}



;; Function int hello() (_Z5hellov)

int hello() ()
{
  int D.2216;

  __builtin_puts (&"Hello world"[0]);
  D.2216 = 0;
  goto <D.2217>;
  <D.2217>:
  return D.2216;
}


