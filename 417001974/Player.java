//417001974
////////////////////////////    PLAYER CLASS   \\\\\\\\\\\\\\\\\\\\\\\\\\


import java.util.ArrayList;//inports the java array list
public class Player
{
	private String name;
	private ArrayList<Simploxide> simploxideStore; //= new ArrayList();
	private ArrayList<ReactionAgent> reactorStore; //= new ArrayList();
	protected int score;
	
	
	
	public Player(String pname)
	{
	   simploxideStore = new ArrayList();
	   reactorStore = new ArrayList();
		name = pname;
		score = 0;
		
	}
	
	
	public void setName(String pname)//Constructor
	{
	   name = pname;
	   
	}
	
	public String getName()
	{
		return name;
	}
	


//Acessor and Mutator 
    public void setSimploxideStore(Ore simplox)
	{
	   simploxideStore.add((Simploxide)simplox);
	}	
	
	
	
	/*public ArrayList getSimploxideStore(int i)
	{
	return simploxideStore.get(i);
		
	}*/
	
	
	
	
	
//Acessor and Mutator	
	public void setReactorStore(ReactionAgent reactor)
	{
	   reactorStore.add(reactor);
	}	
	
	public ArrayList getReactorStore()
	{
	return reactorStore;
		
	}
	
	
	
	
    //Acessor and Mutator	
	public void storeOre(Simploxide newOre)
	{
	 simploxideStore.add(newOre);
	}
	
	public void storeReactor(ReactionAgent newReactionAgent)
	{
	 reactorStore.add(newReactionAgent);
	}
	
	
	
	
	
	//Simploxide simpCalc
	
	//ProcessOre
	public int processOre()
	{
		int size = 0;
		int i = 0;
		size = simploxideStore.size();
		Simploxide simpCalc = new Simploxide();
		Simploxide tempsimp = new Simploxide();
		simpCalc.value = 0;
		//System.out.println(simpCalc.value);
		//System.out.println(" ");
		for( i = 0;i!= size;i++)
		{
			tempsimp=simploxideStore.get(i);
			
			simpCalc.value = simpCalc.value + tempsimp.value;
			//System.out.print(" " + tempsimp.value);
			
		}
		
		/*System.out.println(" ");
		System.out.println(simpCalc.value);
		System.out.println(" ");
		//simpCalc.value;*/
		
		
		
		
		
		
		ReactionAgent reacCalc = new ReactionAgent();
		ReactionAgent reacTemp = new ReactionAgent();
		i =0;
		size = reactorStore.size();
		
		for( i = 0;i!= size;i++)
		{
			reacTemp=reactorStore.get(i);
			if(reacTemp instanceof Augmentium)
			{
			
			simpCalc.value = simpCalc.value + reacTemp.reactionFactor;
			//System.out.print(" " + reacTemp.reactionFactor);
			//System.out.println(" above is d valu nigga");
			}
			
			if(reacTemp instanceof Amplium)
			{
			
			simpCalc.value = simpCalc.value * reacTemp.reactionFactor;
			//System.out.print(" " + reacTemp.reactionFactor);
			//System.out.println(" above is d valu nigga");
			}
			
			
			if(reacTemp instanceof Minucium)
			{
			
			simpCalc.value = simpCalc.value - reacTemp.reactionFactor;
			//System.out.print(" " + reacTemp.reactionFactor);
			//System.out.println(" above is d valu nigga");
			}
			
			
			
		}
		/*System.out.println("");
		System.out.println(simpCalc.value);
		System.out.println("");*/
		//This works 100%
		
		
		
		return simpCalc.value;
	}
	
	
	
	
	

    
	
}	