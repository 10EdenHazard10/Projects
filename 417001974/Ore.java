//417001974
////////////////////////////   ORE CLASS  \\\\\\\\\\\\\\\

public class Ore 
{
	
	protected String type;
	protected char symbol; //Variables
	
	
	public Ore()//Constructor
	{
	
		type = "Ore";
		symbol = 'O';
	
	}
	
	//Mutators and Accessors
	public void setType(String typeore)
	{
		type = typeore;
	}
	
	public String getType()
	{
		return type;
	}
	
	public void setSymbol(char symbolTyp)
	{
		symbol = symbolTyp;
	}
	
	public char getSymbol()
	{
		return symbol;
	}
	
	
	
	
	
	
	
	
	 
	
	
	
}