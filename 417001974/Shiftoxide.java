//417001974
import java.util.Random; // import this library


public class Shiftoxide extends Ore

{
	
	
	private int direction;
	private int Shiftno;
	private int max;
	//private Ore Shiftoxide = new Ore();
	//Constructor
	private Ore newShiftoxide = new Ore();
	public Shiftoxide()
	{
		direction = 0;
		setSymbol('H');
		type = "Shiftoxide";
		Shiftno = 0;
	    max = 2;
	    direction = randNum.nextInt(max); //gets a value between 0 and max(inclusive)
		
	}
	
	//Accessor & Mutator
	public void setDirection(int directionval)
	{
		direction = directionval;
		
	}
	
	
	
	public int getDirection()
	{
		return direction;
	}
	
	
	
	
	Random randNum = new Random();
	
	
	/*public int randNum()
	{
	int max = 2;
	
	
	direction = randNum.nextInt(max); //gets a value between 0 and max(inclusive)
	
	return Shiftno;
	}*/
	
	
	
	
	
	public Ore oreReaction(Ore newOre)//Overriding method
	{
	
	if (newOre instanceof Simploxide)
	{
		int newOreval = ((Simploxide)newOre).getValue();//casts the Ore as Simploxide to acess getValue
		newOreval = Shiftno;
		((Simploxide)newOre).setValue(newOreval);//stes the value
	}	
	
	
		return newOre;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
