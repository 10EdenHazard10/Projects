//417001974
//Kofi McCollin
////////////////////////////   REACTION_AGENT CLASS  \\\\\\\\\\\\\\\\\\\\\\\\\\\\

public class ReactionAgent extends Ore
{
	protected int reactionFactor;  //Variables 
	
	
	
	//Constuctor
	public ReactionAgent()
	{
	reactionFactor = 1;
	}
	
	
	//Asessors & Mutators
	public void setFactor (int Factor)
	{
	reactionFactor = Factor;
	
	}
	
	public int getFactor()
	{
	return reactionFactor;
	}
	
	
    
	
	
	
	public Ore oreReaction(Ore newOre)
	{
	
	if (newOre instanceof Simploxide)
	{
		int newOreval = ((Simploxide)newOre).getValue();//casts the Ore as Simploxide to acess getValue
		newOreval = newOreval + reactionFactor; //
		((Simploxide)newOre).setValue(newOreval);//stes the value
	}	
	
	
	
	
	return newOre;
	}
	
}