//
//  SIEVE. The Sieve of Eratosthenes.
//
//    James B. Moen
//    08 Oct 19
//
//  Test the SIEVE class, for 30 points total.
//

//
//  Put your code for the class SIEVE here!!!
//
class Sieve {
    private boolean[] numbers;
    private int realMax;
  public Sieve(int max){
    if (max<2) 
      throw new IllegalArgumentException();
    numbers = new boolean[max];
    realMax = (max - 1);
    for (int i=2; i<max; i+=1) { numbers[i]=true; }
  }
  public void findPrimes() {
    for (int i=2; i<=realMax; i+=1) {
      //Only look for composite numbers if the number is prime
      if (numbers[i]) {
        for (int j=(i*2); j<=realMax; j+=i) {
          numbers[j]=false;
        }
      }
    //  System.out.println(i);
    }
  }
  public String toString(){
    String str = "";
    for (int n = 0; n <= realMax; n += 1) {
      if (numbers[n]) {
        str += n; str += " ";
      }
    }
    return str;
  }
}
//  TOSS THE KNEES. Run SIEVE on some examples.

class TossTheKnees
{

//  MAIN. Find some primes.

  public static void main(String [] args)
  {
    Sieve sieve = null;  //  We must initialize SIEVE or Java will cry.

//  5 points. This must print "Sieve size must be at least 2." but without the
//  quotes.

    try
    {
      sieve = new Sieve(0);
    }
    catch (IllegalArgumentException oops)
    {
      System.out.println("Sieve size must be at least 2.");
    }

//  5 points. This must print nothing.

    try
    {
      sieve = new Sieve(100);
    }
    catch (IllegalArgumentException oops)
    {
      System.out.println("Sieve size must be at least 2.");
    }

//  10 points. This must print integers from 2 to 99, separated by blanks.

    System.out.println(sieve);

//  10 points. This must print the prime numbers between 2 and 99, separated by
//  blanks. They are:
//
//  2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97

    sieve.findPrimes();
    System.out.println(sieve);
  }
}
