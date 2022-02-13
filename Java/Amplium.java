//417001974
//Kofi McCollin
////////////////////////////   AUGMENTIUM CLASS  \\\\\\\\\\\\\\\\\\\\\\\\\\\\

import java.util.Random; // import this library
public class Amplium extends ReactionAgent //inherits ReactionAgent
{
	private int val;
	private int max; 	
	private int nextInt;
	private int u;
	
	
	
	//Constuctor
	public Amplium()
	{
	val = 1;
	max = 3;
	nextInt = 1;
    setSymbol('X');
	type = "Amplium";
	
	max = 3;
	
	Random randNum = new Random();
	setFactor(randNum.nextInt(max) + 2);
	
	}	

	
	
	
	
	private ReactionAgent newAmplium = new ReactionAgent();
	
	
	
	
	
	
	
	
	
	
	Random randNum = new Random();
	
	
	public void randNum()
	{
	max = 3;
	
	
	newAmplium.setFactor(randNum.nextInt(max) + 2); //gets a value between 2 and max(inclusive)
	//return newAmplium.getFactor();//returns 
	}	
	
	
	
	
	
	
	
	
	public Ore oreReaction(Ore newOre)
	{
	
	if (newOre instanceof Simploxide)
	{
		int newOreval = ((Simploxide)newOre).getValue();//casts the Ore as Simploxide to acess getValue
		newOreval = newOreval * newAmplium.getFactor();
		((Simploxide)newOre).setValue(newOreval);//stes the value
	}	
	
	
		return newOre;//returns the ore
	}
	
	
	
	
	


}