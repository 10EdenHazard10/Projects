//417001974
//Kofi McCollin
////////////////////////////   AUGMENTIUM CLASS  \\\\\\\\\\\\\\\\\\\\\\\\\\\\

import java.util.Random; // import this library
public class Augmentium extends ReactionAgent //inherits Reaction Agent
{
	private int val;
	private int max; 	
	private int nextInt;
	
	
	
	public Augmentium()//Constructor
	{
	val = 1;
	max = 4;
	nextInt = 1;
	setSymbol('A');
	type = "Augmentium";
	
	max = 4;
	
	Random randNum = new Random();
	setFactor(randNum.nextInt(max) + 2);
	}	

	
	
	
	
	ReactionAgent Augmentium = new ReactionAgent();
	
	
	
	
	
	
	Random randNum = new Random();//New Random number Object
	
	
	public int randNum()//Random number generator
	{
	max = 4;
	
	
	Augmentium.setFactor(randNum.nextInt(max) + 2); //gets a value between 2 and max(inclusive)
	return Augmentium.getFactor();
	
	}	
	
	
	
	
	/*public Ore oreReaction(Ore newOre)
	{
	
	if (newOre instanceof Simploxide)
	{
		int newOreval = ((Simploxide)newOre).getValue();
		newOreval = newOreval + Augmentium.reactionFactor;
		((Simploxide)newOre).setValue(newOreval);
	}	
	
	
		return newOre;
	}*/
	
	/*public int getAugmentium1()
	{
	return Augmentium1.reactionFactor;
	}*/
	
	
	
	
	
	
	 /*public static void main(String args[])
    {
        Augmentium test = new Augmentium();
		System.out.println(test.randNum());
		System.out.println(test.getAugmentium1());
		
		
   }*/
	


}