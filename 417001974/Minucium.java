//417001974
//Kofi McCollin
////////////////////////////   MINUCIUM CLASS  \\\\\\\\\\\\\\\\\\\\\\\\\\\\

import java.util.Random; // import this library
public class Minucium extends ReactionAgent
{
	private int val;
	private int max; 	
	private int nextInt;
	private int u;
	
	
	
	
	//Constructor
	public Minucium()
	{
	val = 1;
	max = 4;
	nextInt = 1;
	setSymbol('M');
	type = "Minucium";
	
	max = 3;
	
	Random randNum = new Random();
	setFactor(randNum.nextInt(max) + 1);
	
	
	}	

	
	
	
	
	protected ReactionAgent newMinucium = new ReactionAgent();
	
	
	
	
	
	
	
	
	
	
	
	
	
	Random randNum = new Random();
	
	
	public void randNum()
	{
	max = 3;
	
	
	newMinucium.setFactor(randNum.nextInt(max) + 1); //gets a value between 2 and max(inclusive)
	//return newMinucium.reactionFactor;
	}	
	
	
	
	
	
	public Ore oreReaction(Ore newOre)//Overriding method
	{
	
	if (newOre instanceof Simploxide)
	{
		int newOreval = ((Simploxide)newOre).getValue();//casts the Ore as Simploxide to acess getValue
		newOreval = newOreval - newMinucium.getFactor();
		((Simploxide)newOre).setValue(newOreval);//stes the value
	}	
	
	
		return newOre;
	}
	
	
	
	
	
	
	
	
	


}