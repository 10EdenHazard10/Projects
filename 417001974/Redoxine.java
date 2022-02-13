//417001974


import java.util.Random; // import this library
public class Redoxine extends Ore
{
	
	
	protected boolean isStable;
	private int choice;
	
	//Constructor
	public Redoxine()
	{
		
		isStable = true;
		setSymbol('R');
		type = "Redoxine";
		
		int max = 2;
		choice = randNum.nextInt(max) ; //gets a value between 1 and max(inclusive)
		
		if (choice == 0)//decides if value will be set to true or false
		{
			setRedoxine(true);
		}
	
		if (choice == 1)
		{
		setRedoxine(false);
		}
		
		
	}
	
	//Mutator and Accesor
	
	public boolean getRedoxine ()
	{
		return isStable;
			
	}
	
	public void setRedoxine(boolean choice)
	{
		isStable = choice;
	}
	
	
	
	
	
	
Random randNum = new Random(); // instantiate random generator
public void choiceRed()
{
	int max = 2;
 choice = randNum.nextInt(max) ; //gets a value between 1 and max(inclusive)
	if (choice == 0)//decides if value will be set to true or false
	{
		setRedoxine(true);
	}
	
	if (choice == 1)
	{
		setRedoxine(false);
	}
	
}	
	
	/* public static void main(String args[])
    {
	    Redoxine test = new Redoxine();
		test.choiceRed();
		System.out.println(test.getRedoxine());
		
	
	
	}*/
	
	
	
	
	
	
	
	
	
	
	
	
}