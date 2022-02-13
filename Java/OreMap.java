//417001974
//Kofi McCollin
////////////////////////////   OREMAP CLASS  \\\\\\\\\\\\\\\\\\\\\\\\\\\\


import java.util.Random; // import this library
//import java.util.Scanner;
public class OreMap //extends Player
{

	
	//Variables
	private int rows = 8;
	private int columns = 8;
	protected Ore[][] map;// = new Ore[8][8];
	private int simploxideCount; 
	private int augmentiumCount;
    protected int shiftoxideCount; 
	protected int redoxineCount; 
	private int minuciumCount;
	private int ampliumCount;
	private int nextInt;
	private int max;
	private int element; 
	private char showore[][] = new char[8][8];
	private char removeore[][] = new char[8][8];
	private char specialore[][];
	private int tru = 0;
	
	
	 
	
	
	
	
	 //Constructor
	public OreMap(int r, int c)
	{
		rows = r;
		columns = c;
		map = new Ore[rows][columns];
		
		max = 0;
		element = 0;
		simploxideCount=0; 
	    augmentiumCount=0;
        shiftoxideCount =0; 
	    redoxineCount = 0;
		fillMap();
		specialore = new char[rows][columns];
		
	}
	
	
	
	
	//public void map 
	
	Random randEle = new Random();
	
	public void fillMap()
	{
	 rows=0;
	 while (rows < 8)
	 {
	    
		columns =0;
		while (columns < 8)
		{
		max = 6;	
	 
	
	element = randEle.nextInt(max) + 1;//random number generator to populate map
     
	 if (element == 1 )
	 {
    map[rows][columns] = new Simploxide();	//Sets Ore to Simploxide
	
	//map[rows][columns].setSymbol('S');
	//map[rows][columns].setType("Simploxide");
	
	simploxideCount++;//keeps count of ore
	 }
	 
	 if (element == 2 )
	 {
	 
	 map[rows][columns] = new Augmentium();//Sets Ore to Augmentium
	 //map[rows][columns].setSymbol('A');
     //map[rows][columns].setType("Augmentium");
	 augmentiumCount++;//keeps count of ore
	 }
	 
	 if (element == 3 )
	 {
	 map[rows][columns] = new Minucium();//Sets Ore to Minucium
	 //map[rows][columns].setSymbol('M');
	 //map[rows][columns].setType("Minucium");
	 minuciumCount++;//keeps count of ore
	 }
	 
	 if (element == 4 )
	 {
	 map[rows][columns] = new Amplium();//Sets Ore to Amplium
	 //map[rows][columns].setSymbol('X');
	 //map[rows][columns].setType("Amplium");
	 ampliumCount++;//keeps count of ore
	 }
	 
	 if (element == 5 && shiftoxideCount < 5)
	 {
	 map[rows][columns] = new Shiftoxide();//Sets Ore to Amplium
	 
	 ++shiftoxideCount;//keeps count of ore
	 }
	 
	 if (element == 6 && redoxineCount < 5)
	 {
	 map[rows][columns] = new Redoxine();//Sets Ore to Amplium
	 
	 ++redoxineCount;//keeps count of ore
	 }
	
	
	if(element == 5 && shiftoxideCount == 5 && tru < 1)
	{
		columns--;
		tru = 1;
		
	}
	
	
	
	
	if(element == 6 && redoxineCount == 5 && tru < 1)
	{
		columns--;
		tru = 1;
	}
	tru =0;
	
	
	
	 columns++;//increments 
	 element = 0;
	 
	 
		}
		rows++;
	 }	
	redoxineCount--;
	shiftoxideCount--;	
	}
	
	
	
	
	
	
	
	
	//Displays the Summary screen
	
	public void displayOreSummary()
	{
		System.out.println("Ore Remaining:");
		System.out.println("Simploxide             " + simploxideCount);
		System.out.println("Augmentium             " + augmentiumCount);
		System.out.println("Minucium               " + minuciumCount);
		System.out.println("Amplium                " + ampliumCount);
		System.out.println("Shiftoxide             " + shiftoxideCount);
		System.out.println("Redoxine               " + redoxineCount);
		
		
	}
	
	
	
	
	
	
	
	
	
	
	//////DISPLAY MAP AS HIDDEN\\\\\\\
	
	
	public void displayMapAsHidden()
	{
	
	for (int rows = 0; rows < 8; rows++) 
		{
			for (int columns = 0; columns < 8; columns++)
			{
				
				
				if(removeore[rows][columns] != '-')
					{	
					removeore[rows][columns] = ' ';//If Ore wasnt removed, it displays a " "
					}		
			
			}
		
		}
		
		
		
		rows =0;
		columns =0 ;
		//fillMap();
		System.out.println("**************************************************");
		System.out.println("**************************************************");
		System.out.println("+                   MEMORY MINE                  +");
		System.out.println("**************************************************");
		System.out.println("**************************************************");
		System.out.println("    0     1     2     3     4     5     6     7   ");
	
	 
		 
		 rows=0;
		while (rows != 8)
		{
		System.out.println(rows + "   " + removeore[rows][columns] + "     "  + removeore[rows][columns+1] + "     " + removeore[rows][columns+2] + "     " + removeore[rows][columns+3] + "     " + removeore[rows][columns+4] + "     " + removeore[rows][columns+5] + "     " + removeore[rows][columns+6] + "     " + removeore[rows][columns+7] + "|");	
			
		
	     rows++;
		}
	    displayOreSummary();//Displays summary
	
	}
	
	
	
	
	
	
	
	
	//Displays Map as Visible
	public void displayMapAsVisible()
	{
	
    rows =0;
	columns =0 ;
	//fillMap();
    System.out.println("*****************************************************");
	System.out.println("*****************************************************");
	System.out.println("+                    MEMORY MINE                    +");
	System.out.println("*****************************************************");
	System.out.println("*****************************************************");
	System.out.println("|      0     1     2     3     4     5     6     7  |   ");
	
	
	
	
	
	
	rows = 0;
	while (rows < 8)//loops and prints the corresponding colums wit rows
	{
	if (map[rows][0] == null)
		{
			System.out.print("|" + rows + "--+--" + " ");
		}
		else
		{
			System.out.print("|" + rows + "--+--" + map[rows][0].getSymbol());
		}
	columns = 1;
	
	
	
	while (columns < 8)
	{
		if (map[rows][columns] == null  && columns != 7)
		{
		System.out.print("--+--" + " ");
		
		}
		if (map[rows][columns] != null  && columns != 7)
		{
		System.out.print("--+--" + map[rows][columns].getSymbol());
		
		}
		
		
			if(columns == 7 && map[rows][columns] != null)
			{
				System.out.println("--+--" + map[rows][columns].getSymbol() + "--|" );
				System.out.println("|   |     |     |     |     |     |     |     |     |   ");
			}
			
			if(columns == 7 && map[rows][columns] == null)
			{
				System.out.println("--+--" + " " + "--|" );
				System.out.println("|   |     |     |     |     |     |     |     |     |   ");
			}
			
			/*else
			{
				System.out.print("--+--" + map[rows][columns].getSymbol());
			}*/
		
	    columns++;
	}
	
	rows++;
	
	}
	//System.out.println("|   |     |     |     |     |     |     |     |     |   ");
	displayOreSummary();
	
		
	
	
		
	
	}
	
	 
	 
	 
	 
	 
	 
	 
	 /////////CHECK ORE MATCH\\\\\\\\\\\\\
	 
	 public boolean checkOreMatch(int row1, int col1, int row2, int col2)
	 {
        Shiftoxide tempore;
		if(map[row1][col1] == null)
		{
		    return false;	
		}
		
		if(map[row2][col2] == null)
		{
		    return false;	
		}
		
		if(map[row1][col1].getSymbol() == map[row2][col2].getSymbol())//verifies map posittion symbols are similar
		{
		   if(row1 == row2 && col1 == col2)//Checks to see if coordinates are the same
		   {
			   System.out.println("You have entered the same coordinates");
			   
			   
		   }
		   
		   
		   
		   if(map[row1][col1] instanceof Shiftoxide && map[row2][col2] instanceof Shiftoxide)
		   {
			    
				tempore = (Shiftoxide)map[row2][col2];
				int rowtemp = row2;
                int coltemp = col2;
				System.out.println("YOU WILL HAVE");
				shiftOre((Shiftoxide)map[row1][col1], row2);
				//removeOre(row1, col1);//map[row1][col1] = null;
				
				shiftOre(tempore, row2);
				//removeOre(row2, col2);//map[row1][col1] = null;
			   
			   
		   }
		   
		   
		   
		   
		   /*if (map[row1][col1] instanceof Shiftoxide)
			{
				

				System.out.println("You have");
				shiftOre((Shiftoxide)map[row1][col1], row2);
				removeOre(row1, col1);//map[row1][col1] = null;
			}	
		   
		   
		   if (map[row2][col2] instanceof Shiftoxide)
			{
				System.out.println("You have 22222");
				shiftOre((Shiftoxide)map[row2][col2], row1);
				removeOre(row2, col2);//map[row2][col2] = null;
				
		    }*/
		   
		   
		return true;
		}
     

			/*if (map[r][c] != null && map[r][c] instanceof Shiftoxide)
			{
				shiftOre(map[row1][col1], row2);
				shiftOre(map[row2][col2], row1);
			}*/
	 
	        if (map[row1][col1] instanceof Shiftoxide)
			{
				

				System.out.println("You have");
				shiftOre((Shiftoxide)map[row1][col1], row2);
				//removeOre(row1, col1);//map[row1][col1] = null;
				
				
				
			}  
			if (map[row2][col2] instanceof Shiftoxide)
			{
				//System.out.println("You have 22222");
				shiftOre((Shiftoxide)map[row2][col2], row1);
				//removeOre(row2, col2);//map[row2][col2] = null;
				
		    }
	 
	 
	 return false;

	 }		 
	 
	 
	 
	 /////////MINE ORE\\\\\\\
	 
	 public Ore mineOre(int r, int c)
	 {
		 
		return map[r][c]; //returns ore at this position


	 }
	 
	 
	 
	 
	/////////REMOVE ORE\\\\\\\\\

     public void removeOre(int r, int c)
	 {
		 
	 if(map[r][c] != null)
	 {		 
       switch (map[r][c].getSymbol())//switch statement to check which ore has been removed
	   {

        case 'S':
		simploxideCount--;
		break;
		
        case 'M':
		minuciumCount--;
		break;
		
		case 'X':
		ampliumCount--;
		break;
		
		case 'A':
		augmentiumCount--;
		break;
		
		case 'R':
		redoxineCount--;
		break;
		
		case 'H':
		shiftoxideCount--;
		break;
		
		 
		 
	   
	   
	   }
		//map[r][c] = new Ore();
		map[r][c].setSymbol(' ');//removes  symbol
		map[r][c].setType("  ");//removes type
		removeore[r][c] = '-';  //sets this to '-' to help removeore function
		map[r][c] = null;//could reomove
	 }
	 }
	 
	 
	 





	 ///////SHOW ORE\\\
	 
	 
	
	 
	 
	 
	 
	 public void showOre(int row1, int col1, int row2, int col2)
	 {
		
		
		
		
		for (int rows = 0; rows < 8; rows++) 
		{
			for (int columns = 0; columns < 8; columns++)
			{
				
				
				if(rows == row1 && columns == col1)
				{
					if(map[rows][columns] == null)
						showore[rows][columns] = '_';
					else	
					showore[rows][columns] = map[rows][columns].getSymbol();//uses a new array to store the position tobe displayed
					
					
				}
                
				if(rows == row2 && columns == col2)
					{
						if(map[rows][columns] == null)
						showore[rows][columns] = '_';
						
						else
						showore[rows][columns] = map[rows][columns].getSymbol();//uses a new array to store the position tobe displayed
						
					}
				
				/*if((rows != row1 || columns != col1) && (rows != row2 || columns != col2))
					{	
					showore[rows][columns] = ' ';//set all other positions in the map to blank
					}	*/	
			
			}
		
		}
		
		
		
		rows =0;
		columns =0 ;
		//FILLS Map
		System.out.println("*****************************************************");
		System.out.println("*****************************************************");
		System.out.println("+                    MEMORY MINE                    +");
		System.out.println("*****************************************************");
		System.out.println("*****************************************************");
		System.out.println("|      0     1     2     3     4     5     6     7  |   ");
	
	 
		 
		 rows=0;
		while (rows != 8)
		{
		System.out.println("|" + rows + "--+--" + showore[rows][columns] + "--+--"  + showore[rows][columns+1] + "--+--" + showore[rows][columns+2] + "--+--" + showore[rows][columns+3] + "--+--" + showore[rows][columns+4] + "--+--" + showore[rows][columns+5] + "--+--" + showore[rows][columns+6] + "--+--" + showore[rows][columns+7] + "--|" );	
		System.out.println("|   |     |     |     |     |     |     |     |     |   ");	
	     rows++;
		}
	
	    
	
	  
	
	    displayOreSummary();//Displays summary
		
		 
		 
		 
		 
	 }
	 
	 
	 
	 
	 
	 
	 public int getSimpl()//Used to get the simpleoxide count to make sure it doesnt go past 0
	 {
		 
		 return simploxideCount;
	 }
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 //Display Mine As Special
	 
	 public void displayMineAsSpecial(int r1, int c1, int r2, int c2)//, int r2, int c2)
	 {
		 
		 
		 int j = 0;
		 
		
		 
		 
		 
		 
		 int truu = 0;
		 
		 
		 
		 
		  for (int rows = 0; rows < 8; rows++) 
		{
			for (int columns = 0; columns < 8; columns++)
			{
				specialore[rows][columns]=' ';
			}
		
		}
		 
		 
		 
		while(j < 2)
		{			
		 
		 if(j == 1)
		 {
			 r1 = r2;
			 c1 = c2;
		 }
		 
		 
		 for (int rows = 0; rows < 8; rows++) 
		{
			for (int columns = 0; columns < 8; columns++)
			{
				if((rows == r1 && columns == c1) || (rows == r2 && columns == c2))
				{
					
						if(rows == r2 && columns == c2)
						{
							r1 = r2;
							c1 = c2;
							
						}
						
						//while (truu != 2)
						//CORNERS
						//{
						
						
						
						
						if((r1 == 0) && (c1 == 0))//top left
						{
						
						if(map[rows][columns] != null){specialore[rows][columns] = map[rows][columns].getSymbol();}//uses a new array to store the position tobe displayed
						if(map[rows][columns+1] != null){specialore[rows][columns+1] = map[rows][columns+1].getSymbol();}
						if(map[rows+1][columns] != null){specialore[rows+1][columns] = map[rows+1][columns].getSymbol();}
						if(map[rows+1][columns+1] != null){specialore[rows+1][columns+1] = map[rows+1][columns+1].getSymbol();}
						
						} 
							
							
						
					    else if((r1 == 7) && (c1 == 0))//bottom left
						{
						
						if(map[rows][columns] != null){specialore[rows][columns] = map[rows][columns].getSymbol();}//uses a new array to store the position tobe displayed
						if(map[rows][columns+1] != null){specialore[rows][columns+1] = map[rows][columns+1].getSymbol();}
						if(map[rows-1][columns] != null){specialore[rows-1][columns] = map[rows-1][columns].getSymbol();}
						if(map[rows-1][columns+1] != null){specialore[rows-1][columns+1] = map[rows-1][columns+1].getSymbol();}
						
						} 
					
					    else if(r1 == 0 && c1 == 7)//top right
						{
						
						if(map[rows][columns] != null){specialore[rows][columns] = map[rows][columns].getSymbol();}//uses a new array to store the position tobe displayed
						if(map[rows][columns-1] != null){specialore[rows][columns-1] = map[rows][columns-1].getSymbol();}
						if(map[rows+1][columns] != null){specialore[rows+1][columns] = map[rows+1][columns].getSymbol();}
						if(map[rows+1][columns-1] != null){specialore[rows+1][columns-1] = map[rows+1][columns-1].getSymbol();}
						
						}
							
					    else if(r1 == 7 && c1 == 7)//bottom right
						{
						
						if(map[rows][columns] != null){specialore[rows][columns] = map[rows][columns].getSymbol();}//uses a new array to store the position tobe displayed
						if(map[rows][columns-1] != null){specialore[rows][columns-1] = map[rows][columns-1].getSymbol();}
						if(map[rows-1][columns] != null){specialore[rows-1][columns] = map[rows-1][columns].getSymbol();}
						if(map[rows-1][columns-1] != null){specialore[rows-1][columns-1] = map[rows-1][columns-1].getSymbol();}
						
						}
					
					
					
					
					    //EDGE
					    else if((r1 > 0 && r1 < 7) && (c1 == 0))//LEFT
						{
						
						if(map[rows][columns] != null){specialore[rows][columns] = map[rows][columns].getSymbol();}//uses a new array to store the position tobe displayed
						if(map[rows][columns+1] != null){specialore[rows][columns+1] = map[rows][columns+1].getSymbol();}
						if(map[rows-1][columns] != null){specialore[rows-1][columns] = map[rows-1][columns].getSymbol();}
						if(map[rows-1][columns+1] != null){specialore[rows-1][columns+1] = map[rows-1][columns+1].getSymbol();}
						if(map[rows+1][columns] != null){specialore[rows+1][columns] = map[rows+1][columns].getSymbol();}
						if(map[rows+1][columns+1] != null){specialore[rows+1][columns+1] = map[rows+1][columns+1].getSymbol();}
						}
					
					
					
					    else if((r1 > 0 && r1 < 7) && (c1 == 7))//RIGHT
						{
						
						if(map[rows][columns] != null){specialore[rows][columns] = map[rows][columns].getSymbol();}//uses a new array to store the position tobe displayed
						if(map[rows][columns-1] != null){specialore[rows][columns-1] = map[rows][columns-1].getSymbol();}
						if(map[rows-1][columns] != null){specialore[rows-1][columns] = map[rows-1][columns].getSymbol();}
						if(map[rows-1][columns-1] != null){specialore[rows-1][columns-1] = map[rows-1][columns-1].getSymbol();}
						if(map[rows+1][columns] != null){specialore[rows+1][columns] = map[rows+1][columns].getSymbol();}
						if(map[rows+1][columns-1] != null){specialore[rows+1][columns-1] = map[rows+1][columns-1].getSymbol();}
						}
						
						
						
						
						
						
						
						else if((c1 > 0 && c1 < 7) && (r1 == 0))//TOP
						{
						
						if(map[rows][columns] != null){specialore[rows][columns] = map[rows][columns].getSymbol();}//uses a new array to store the position tobe displayed
						if(map[rows][columns-1] != null){specialore[rows][columns-1] = map[rows][columns-1].getSymbol();}
						if(map[rows][columns+1] != null){specialore[rows][columns+1] = map[rows][columns+1].getSymbol();}
						if(map[rows+1][columns] != null){specialore[rows+1][columns] = map[rows+1][columns].getSymbol();}
						if(map[rows+1][columns+1] != null){specialore[rows+1][columns+1] = map[rows+1][columns+1].getSymbol();}
						if(map[rows+1][columns-1] != null){specialore[rows+1][columns-1] = map[rows+1][columns-1].getSymbol();}
						}
						
						
						
						
						
						else if((c1 > 0 && c1 < 7) && (r1 == 7))//BOTTOM 
						{
						
						if(map[rows][columns] != null){specialore[rows][columns] = map[rows][columns].getSymbol();}//uses a new array to store the position tobe displayed
						if(map[rows][columns-1] != null){specialore[rows][columns-1] = map[rows][columns-1].getSymbol();}
						if(map[rows][columns+1] != null){specialore[rows][columns+1] = map[rows][columns+1].getSymbol();}
						if(map[rows-1][columns] != null){specialore[rows-1][columns] = map[rows-1][columns].getSymbol();}
						if(map[rows-1][columns+1] != null){specialore[rows-1][columns-1] = map[rows-1][columns+1].getSymbol();}
						if(map[rows-1][columns-1] != null){specialore[rows-1][columns-1] = map[rows-1][columns-1].getSymbol();}
						}
						
						
						
						
						
					
					
					
					
					    else//ALTERNATE
						{
						
						if(map[rows][columns] != null){specialore[rows][columns] = map[rows][columns].getSymbol();}//uses a new array to store the position tobe displayed
						if(map[rows][columns+1] != null){specialore[rows][columns+1] = map[rows][columns+1].getSymbol();}
						if(map[rows-1][columns] != null){specialore[rows-1][columns] = map[rows-1][columns].getSymbol();}
						if(map[rows-1][columns+1] != null){specialore[rows-1][columns+1] = map[rows-1][columns+1].getSymbol();}
						if(map[rows+1][columns] != null){specialore[rows+1][columns] = map[rows+1][columns].getSymbol();}
						if(map[rows+1][columns+1] != null){specialore[rows+1][columns+1] = map[rows+1][columns+1].getSymbol();}
						if(map[rows][columns-1] != null){specialore[rows][columns-1] = map[rows][columns-1].getSymbol();}
						if(map[rows-1][columns-1] != null){specialore[rows-1][columns-1] = map[rows-1][columns-1].getSymbol();}
						if(map[rows+1][columns-1] != null){specialore[rows+1][columns-1] = map[rows+1][columns-1].getSymbol();}
						}
					
					
					    //c1 = c2;
						//r1 = r2;
						
					
					
					    //}
					
		
					
					
					
					
				}
		 
		    }
		 
		 
	    }
		j++;
		}



		rows =0;
		columns =0 ;
		//FILLS Map
		System.out.println("*****************************************************");
		System.out.println("*****************************************************");
		System.out.println("+                    MEMORY MINE                    +");
		System.out.println("*****************************************************");
		System.out.println("*****************************************************");
		System.out.println("|      0     1     2     3     4     5     6     7  |   ");
	
	 
		 
		rows=0;
		while (rows != 8)
		{
		System.out.println("|" + rows + "--+--" + specialore[rows][columns] + "--+--"  + specialore[rows][columns+1] + "--+--" + specialore[rows][columns+2] + "--+--" + specialore[rows][columns+3] + "--+--" + specialore[rows][columns+4] + "--+--" + specialore[rows][columns+5] + "--+--" + specialore[rows][columns+6] + "--+--" + specialore[rows][columns+7] + "--|" );	
		System.out.println("|   |     |     |     |     |     |     |     |     |   ");	
	    rows++;
		}
	
	
	
	    displayOreSummary();//Displays summary
	
	 
	  /*else
	  {
		 System.out.print(""); System.out.print(""); System.out.print(""); 
		 System.out.print("Cannot Print the desired output because a value is equal to null"); 
		 System.out.print(""); System.out.print(""); System.out.print("");
	  }*/
	
	}
	 
	 
	 
	 
	public boolean isShiftoxide(int r, int c)
	{
		
		if (map[r][c] != null && map[r][c] instanceof Shiftoxide)
		{
			return true;
		}
		
		return false;
	}



    public void shiftOre(Shiftoxide shifter, int row)
	{
      Ore temp;
	  char temp1 = ' ';
	  int temp2 = 0;
	  int i =0;
         if (shifter.getDirection() == 0) //|| shifter.getDirection() == 1)
		 {
			//shifter = null;
			
			if( map[row][0] != null) 
			{
				System.out.println("Exception needs to be thrown here");
				//System.out.println(map[row][0].getSymbol());
			}				
			if( map[row][0] == null)
			{
				
				map[row][0] = map[row][1];
				map[row][1] = null;
				map[row][1] = map[row][2];
				map[row][2] = null;
				map[row][2] = map[row][3];
				map[row][3] = null;
				map[row][3] = map[row][4];
				map[row][4] = null;
				map[row][4] = map[row][5];
				map[row][5] = null;
				map[row][5] = map[row][6];
				map[row][6] = null;
				//System.out.println(map[row][6]);
				 
				map[row][6] = map[row][7];
				map[row][7] = null;
				//System.out.println(map[row][6]);
				//removeOre(row,7);
				
				
				
				
				
				
				
				/* while(i < 8)
				 {
					
					if (i == 7)
					{
					    map[row][7].symbol = temp1;
	
					}
					else
					{
						map[row][i] = map[row][i+1];
						System.out.println("does ti get to here");					
						//temp2 = 1;
					}
				    i++;
				 }*/
				
				
			}
			 removeOre(shifter);
		 }

         else if (shifter.getDirection() == 1) //|| shifter.getDirection() == 1)
		 {
			if( map[row][7] != null) 
			{
				System.out.println("Exception needs to be thrown here");
				//System.out.println(map[row][0].getSymbol());
			}				
			if( map[row][7] == null)
			{
				
				map[row][7] = map[row][6];
				map[row][6] = null;
				map[row][6] = map[row][5];
				map[row][5] = null;
				map[row][5] = map[row][4];
				map[row][4] = null;
				map[row][4] = map[row][3];
				map[row][3] = null;
				map[row][3] = map[row][2];
				map[row][2] = null;
				map[row][2] = map[row][1];
				map[row][1] = null;
				//System.out.println(map[row][6]);
				 
				map[row][1] = map[row][0];
				map[row][0] = null;
				
				
				
			}
			 removeOre(shifter);
	
	
	
	
	     }
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	}		



/////////REMOVE ORE OVERRIDEN\\\\\\\\\

     public void removeOre(Shiftoxide Shift)
	 {
		 
	 if(Shift != null)
	 {		 
       switch (Shift.getSymbol())//switch statement to check which ore has been removed
	   {

        case 'S':
		simploxideCount--;
		break;
		
        case 'M':
		minuciumCount--;
		break;
		
		case 'X':
		ampliumCount--;
		break;
		
		case 'A':
		augmentiumCount--;
		break;
		
		case 'R':
		redoxineCount--;
		break;
		
		case 'H':
		shiftoxideCount--;
		break;
		
		 
		 
	   
	   
	   }
		//map[r][c] = new Ore();
		Shift.setSymbol(' ');//removes  symbol
		Shift.setType("  ");//removes type
		//removeore[r][c] = '-';  //sets this to '-' to help removeore function
		Shift = null;//could reomove
	 }
	 }




	boolean isRedoxine(int r, int c)
	{
		if(map[r][c] != null && map[r][c] instanceof Redoxine)
		{
			return true;
			
		}
	   	return false;
	}
	
	
	
	void diminishOre(int row, int col)
	{
		
		
		
		if(isRedoxine(row,col) == true)
		{
			
			Redoxine temp = (Redoxine)map[row][col];
		
		
			if(temp.getRedoxine() == false )
			{
			
			
			
						if((row == 0) && (col == 0))//top left
						{
						
						
						removeOre(row,col); //= map[rows][columns].getSymbol();//uses a new array to store the position tobe displayed
						removeOre(row,col+1);
						removeOre(row+1,col);
						removeOre(row+1,col+1);
						
						
						} 
							
							
						
					    else if((row == 7) && (col == 0))//bottom left
						{
						removeOre(row,col);
						removeOre(row,col+1);
						removeOre(row-1,col);
						removeOre(row-1,col+1);
						
						
						} 
					
					    else if(row == 0 && col == 7)//top right
						{
						
						removeOre(row,col);
						removeOre(row,col-1);
						removeOre(row+1,col);
						removeOre(row+1,col-1);
						
						
						}
							
					    else if(row == 7 && col == 7)//bottom right
						{
						
						removeOre(row,col);
						removeOre(row,col-1);
						removeOre(row-1,col);
						removeOre(row-1,col-1);
						
						
						}
					
					
					
					
					    //EDGE
					    else if((row > 0 && row < 7) && (col == 0))//LEFT
						{
						
						removeOre(row,col);
						removeOre(row,col+1);
						removeOre(row-1,col);
						removeOre(row-1,col+1);
						removeOre(row+1,col);
						removeOre(row+1,col+1);
						
						}
					
					
					
					    else if((row > 0 && row < 7) && (col == 7))//RIGHT
						{
						
						removeOre(row,col);
						removeOre(row,col-1);
						removeOre(row-1,col);
						removeOre(row-1,col-1);
						removeOre(row+1,col);
						removeOre(row+1,col-1);
						
						}
					
					
					    else if(row == 0 && col != 0 || col != 7)
						{
							removeOre(row,col);
						    removeOre(row,col-1);
							removeOre(row,col+1);
							removeOre(row+1,col);
							removeOre(row+1,col-1);
							removeOre(row+1,col+1);
							
						}
						
						
						
						
						 else if(row == 7 && col != 0 || col != 7)
						{
							removeOre(row,col);
						    removeOre(row,col-1);
							removeOre(row,col+1);
							removeOre(row-1,col);
							removeOre(row-1,col-1);
							removeOre(row-1,col+1);
							
						}
					
					
					
					    else//ALTERNATE
						{
						
						removeOre(row,col);
						removeOre(row,col+1);
						removeOre(row-1,col);
						removeOre(row-1,col+1);
						removeOre(row+1,col);
						removeOre(row+1,col+1);
						removeOre(row,col-1);
						removeOre(row-1,col-1);
						removeOre(row+1,col-1);
						
						
						}
			
			
			 
				System.out.println("");
				System.out.println("Redoxine was unstable this time");
				System.out.println("");
			
			}
			if(temp.getRedoxine() == false )
			{
				System.out.println("");
				System.out.println("Redoxine was stable this time");
				System.out.println("");
				
		
		
			}
		
		}
		
		
	}
	
	
	
	
	
	
	
	public void randomDelete(int row, int col)//This is a method added to help with the random removal of ore
	{
		
		



		
						if((row == 0) && (col == 0))//top left
						{
						
						

						
						
						removeOre(row,col); //= map[rows][columns].getSymbol();//uses a new array to store the position tobe displayed
						removeOre(row,col+1);
						removeOre(row+1,col);
						removeOre(row+1,col+1);
						
						
						} 
							
							
						
					    else if((row == 7) && (col == 0))//bottom left
						{
						
						
						
						
						
						removeOre(row,col);
						removeOre(row,col+1);
						removeOre(row-1,col);
						removeOre(row-1,col+1);
						
						
						} 
					
					    else if(row == 0 && col == 7)//top right
						{
						
						
						
						
						removeOre(row,col);
						removeOre(row,col-1);
						removeOre(row+1,col);
						removeOre(row+1,col-1);
						
						
						}
							
					    else if(row == 7 && col == 7)//bottom right
						{
						
						
						
						
						removeOre(row,col);
						removeOre(row,col-1);
						removeOre(row-1,col);
						removeOre(row-1,col-1);
						
						
						}
					
					
					
					
					    //EDGE
					    else if((row > 0 && row < 7) && (col == 0))//LEFT
						{
						
						
						
						
						removeOre(row,col);
						removeOre(row,col+1);
						removeOre(row-1,col);
						removeOre(row-1,col+1);
						removeOre(row+1,col);
						removeOre(row+1,col+1);
						
						}
					
					
					
					    else if((row > 0 && row < 7) && (col == 7))//RIGHT
						{
						
						
						
						
						
						
						removeOre(row,col);
						removeOre(row,col-1);
						removeOre(row-1,col);
						removeOre(row-1,col-1);
						removeOre(row+1,col);
						removeOre(row+1,col-1);
						
						}
					
					
					    else if((col > 0 && col < 7) && (row == 0))//TOP
						{
							
							
						
							
							
							
							removeOre(row,col);
						    removeOre(row,col-1);
							removeOre(row,col+1);
							removeOre(row+1,col);
							removeOre(row+1,col-1);
							removeOre(row+1,col+1);
							
						}
						
						
						
						
						 else if((col > 0 && col < 7) && (row == 7))//BOTTOM
						{
							
							
							
							
							
							removeOre(row,col);
						    removeOre(row,col-1);
							removeOre(row,col+1);
							removeOre(row-1,col);
							removeOre(row-1,col-1);
							removeOre(row-1,col+1);
							
						}
					
					
					
					    else//ALTERNATE
						{
						
						removeOre(row,col);
						removeOre(row,col+1);
						removeOre(row-1,col);
						removeOre(row-1,col+1);
						removeOre(row+1,col);
						removeOre(row+1,col+1);
						removeOre(row,col-1);
						removeOre(row-1,col-1);
						removeOre(row+1,col-1);
						
						
						}
			
			
			
			
			
			}
		
		
		
		
		
		
		
		public int[][] randomStore(int row, int col)//This is a method added to help with the random storing of ore
	{
		
		int temparray[][] = new int[9][2];
		int i = 0;
		int j = 0;

				for(i = 0; i < 9; i++)
				{
					temparray[i][j] = 10;
					temparray[i][j+1] = 10;
					
				}
				i=0;
				j=0;
		
						if((row == 0) && (col == 0))//top left
						{
						
						if(map[row][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row+1][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row+1][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}

						
						
						
						
						
						} 
							
							
						
					    else if((row == 7) && (col == 0))//bottom left
						{
						
						
						if(map[row][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row-1][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row-1][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						
						
						
						
						
						} 
					
					    else if(row == 0 && col == 7)//top right
						{
						
						
						if(map[row][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row+1][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row+1][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						
						
						
						
						
						}
							
					    else if(row == 7 && col == 7)//bottom right
						{
						
						if(map[row][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row-1][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row-1][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						
						
						
						
						
						}
					
					
					
					
					    //EDGE
					    else if((row > 0 && row < 7) && (col == 0))//LEFT
						{
						
						
						if(map[row][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row-1][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row-1][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row+1][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row+1][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						
						
						
						}
					
					
					
					    else if((row > 0 && row < 7) && (col == 7))//RIGHT
						{
						
						
						if(map[row][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row-1][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row-1][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row+1][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row+1][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						
						
						
						
						
						}
					
					
					    else if((col > 0 && col < 7) && (row == 0))//TOP
						{
							
							
						if(map[row][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row+1][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row+1][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						if(map[row+1][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							
							
							
							
							
						}
						
						
						
						
						 else if((col > 0 && col < 7) && (row == 7))//BOTTOM
						{
							
							
							if(map[row][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row-1][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row-1][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row-1][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							
							
							
							
						}
					
					
					
					    else//ALTERNATE
						{
						
						
							if(map[row][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row-1][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row-1][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row+1][col] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row+1][col+1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row-1][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
							if(map[row+1][col-1] instanceof Simploxide ){temparray[i][j] = row; temparray[i][j+1] = col; i++;}
						
						
						
						
						
						}
			
			
			 return temparray;
			
			
			}
		
		
		
	


























}