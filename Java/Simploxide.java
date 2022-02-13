//417001974
//Kofi McCollin
////////////////////////////   SIMPLOXIDE CLASS  \\\\\\\\\\\\\\\\\\\\\\\\\\\\


import java.util.Random; // import this library
public class Simploxide extends Ore //Inherits from the ore class
{
	protected int value;
    private int max;
      
    private Ore newSimploxide = new Ore();
  


  
   public Simploxide()//Constructor
	{
		value = 0;
		
		setSymbol('S');
		type = "Simploxide";
		
		
		Random randNum = new Random();
	
	
		
		max = 3;
	
	
		value = randNum.nextInt(max) + 1; //gets a value between 1 and 3(inclusive)
		//return value;
		
		
		
	}	

   
   //Mutators and acessors
   public void setValue(int val)
	{
		value = val;
	}	


    public int getValue()
	{
	 return value;
	}		
	
	
	
	//private Ore newSimploxide = new Ore();
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}