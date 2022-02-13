//417001974
//Kofi McCollin
////////////////////////////   OREMAP CLASS  \\\\\\\\\\\\\\\\\\\\\\\\\\\\

import java.util.Random; // import this library
import java.util.Scanner;
public class MemoryMine 

{



	 public static void main(String args[])
    {
        
		Random randNum = new Random(); // instantiate random generator
		int choice = 0;
		char Simpcheck = 'S'; 
		int checkTrue = 0;
		OreMap test = new OreMap(8,8);//Instansiates OreMap
		int simpchecktru = 0;
		int displaychoice = 0;
		
		int temparray[][] = new int[2][9];
		
		
		System.out.println("Hello welcome to the Memory Mine demo version, you have been approved as an official beta tester, please enter your name");
		Scanner name = new Scanner(System.in);
		System.out.println("");System.out.println("");System.out.println("");System.out.println("");

	    String pname = name.nextLine();//takes in players name
		Player player = new Player(pname);//Instansiates Player
		//player.setName(pname);
		
		
		
		System.out.println("");System.out.println("");System.out.println("");System.out.println("");
		//test.OreMap(8,8);//creates an instance of ore map
		
		
		System.out.println("");System.out.println("");System.out.println("");System.out.println("");
		
		
		test.displayMapAsVisible();//displays map as visble
		
		
		System.out.println("");System.out.println("");System.out.println("");System.out.println("");
		
		
		test.displayMapAsHidden();//displays map as hidden 
		
		
		System.out.println("");System.out.println("");System.out.println("");System.out.println("");
		
		
		
		while(choice != 1 && test.getSimpl() > 1)// choice is wheter the player decides to keep on mining
		{
		
		displaychoice = randNum.nextInt(7) + 1;// Random number generated to decide what to display in the game 
		
		
		System.out.println(player.getName() + " Please enter the coordinates you wish to mine");//prompts the user to enter 
		System.out.println("");
		System.out.println("");
		simpchecktru = 0;
		Scanner input1 = new Scanner(System.in);//variables that gets coordinate input from the user 
		Scanner input2 = new Scanner(System.in);
		Scanner input3 = new Scanner(System.in);
		Scanner input4 = new Scanner(System.in);
		
		
		
		
        int co1 = input1.nextInt();
		int co2 = input2.nextInt();
		int co3 = input3.nextInt();
		int co4 = input4.nextInt();
		
		
		if ((co1 < 7 && co2 < 7 && co3 < 7 && co4 < 7) && (co1 != co3 || co2 != co4 ))//if coordinate are less than 7 and not equal   
		
		{
		
		
			if (test.checkOreMatch(co1,co2,co3,co4) == true )//checks tosee if ore matches
			{
				
			
					
				
				checkTrue = 1;
				
				test.diminishOre(co1,co2);
	            test.diminishOre(co3,co4);
				
				
				
				
				
				
				if(test.map[co1][co2] == null && test.map[co3][co4] == null)
				{
					simpchecktru = 1; 
					
				}
				
				if	(simpchecktru == 0)
				{ 
					if(test.map[co1][co2] instanceof Simploxide)
					{
						player.storeOre((Simploxide)test.mineOre(co1,co2));
										
					}
					if(test.map[co3][co4] instanceof Simploxide)
					{
						player.storeOre((Simploxide)test.mineOre(co3,co4));//stores Simploxide ore
					}
				
				}
				
				
				
				if(!(test.map[co1][co2] instanceof Redoxine) && !(test.map[co1][co2] instanceof Simploxide)) //had not equal
				{
					player.storeReactor((ReactionAgent)test.mineOre(co1,co2));
										
				}
				
				if(!(test.map[co3][co4] instanceof Redoxine) && !(test.map[co3][co4] instanceof Simploxide)) //had not equal
				{
					player.storeReactor((ReactionAgent)test.mineOre(co3,co4));
										
				}
				
				
				
				if(displaychoice == 3 || displaychoice == 5)
				{
					test.displayMineAsSpecial(co1,co2,co3,co4);
					
					if(!(test.map[co1][co2] instanceof Redoxine) && !(test.map[co1][co2] instanceof Simploxide)) //had not equal
					{
						player.storeReactor((ReactionAgent)test.mineOre(co1,co2));
										
					}
				
					if(!(test.map[co3][co4] instanceof Redoxine) && !(test.map[co3][co4] instanceof Simploxide)) //had not equal
					{
						player.storeReactor((ReactionAgent)test.mineOre(co3,co4));
										
					}
					
					
					int p = 0;
					int q = 0;
					int temp1 = 0;
					int temp2 = 0;
					int counter =0;
					
					int tempco1 = 0;
					int tempco2 = 0;
					while(counter < 2)
					{
						tempco1 = co1;
						tempco2 = co2;
						
						if(counter == 1)
						{
							 tempco1 = co3;
							 tempco2 = co4;
						}
						temparray = test.randomStore(tempco1,tempco2) ;
						for(p=0; p < 9; p++)
						{
							if (temparray[p][q] != 10 ) 
							{
								temp1=temparray[p][q];
								if (temparray[p][q+1] != 10 ) 
								{
									temp2=temparray[p][q+1];
									if (test.map[temp1][temp2] instanceof Simploxide)
									{
									player.storeOre((Simploxide)test.mineOre(temp1,temp2));
									}
								}
							}	
						counter++;
						}
					
					
					}
					test.randomDelete(co1,co2);
					test.randomDelete(co3,co4);
				}
				if(displaychoice != 3 && displaychoice != 5)
				{
					test.showOre(co1,co2,co3,co4);
				}
				
				test.removeOre(co1,co2);
				test.removeOre(co3,co4);//removes ore
				
				
				
				
				
				
				
				
				
				
				
				//if (check == Simploxide)
				//{
					//System.out.println("yes nigga");
				//}
				
				
				
			    System.out.println(" ");
				System.out.println("Congractulations, Ore has been sucessfully mined!!");
				
				System.out.println(" ");
//*1			//test.displayMapAsVisible();//displays map as visible to show ore that has been mined
				System.out.println(" ");
				System.out.println(" ");
				System.out.println(" ");
//*2			//test.displayMapAsHidden();//displays map as visible to show ore that has been mined
				System.out.println(" ");System.out.println(" ");System.out.println(" ");
//*3			//test.showOre(3,4,5,6);
				System.out.println(" ");System.out.println(" ");System.out.println(" ");
			
			}
			
			
			
			if (checkTrue == 0)
			{
			System.out.println(" ");
			System.out.println("The coordinates do not match");//prompt if ore match is false
			System.out.println(" ");
		
		    test.diminishOre(co1,co2);
	        test.diminishOre(co3,co4);
		
		
		
			}
		
		checkTrue = 0;
		}
		
		else if(co1 > 7 || co2 > 7 || co3 > 7|| co4 > 7)//checks if coordinates enterd are too big, if so prompts user
		{
			System.out.println("Those Coordinates you have entered are too big");//	
		}
		
		else if(co1 == co2 || co1 == co3 || co1 == co4)//checks if coordinates are same
		{
			System.out.println("These coordinates you entered are the same");//prompts user if coordinates are same
		}
		
		
		//System.out.println("");
		System.out.println("");System.out.println("");System.out.println("");System.out.println("");
		System.out.println(" If you dont wish to continue mining, please enter 1");
		System.out.println(" If you to see map in visble mode , please enter 2");
		System.out.println(" If you to see map in hidden mode , please enter 3");
		System.out.println(" If you to see selected ore , please enter 4");
		System.out.println(" If you wish to end the game  press any other number");
		
		
		
		System.out.println("");System.out.println("");
		Scanner input5 = new Scanner(System.in);
		choice = input5.nextInt();//gives user a choice if to keep mining
		
		
		
		if (choice == 2)
		{
			test.displayMapAsVisible();
		}
		
		if (choice == 3)
		{
			test.displayMapAsHidden();
		}
		
		if (choice == 4)
		{
		
		 
		
		System.out.println("Please enter the coordinates you wish to see");
		//Scanner input1 = new Scanner(System.in);//variables that gets coordinate input from the user 
		//Scanner input2 = new Scanner(System.in);
		//Scanner input3 = new Scanner(System.in);
		//Scanner input4 = new Scanner(System.in);
		
		
		
		
         co1 = input1.nextInt();
		 co2 = input2.nextInt();
		 co3 = input3.nextInt();
		 co4 = input4.nextInt();
		test.showOre(co1,co2,co3,co4);
		}
		
		
		if (choice == 5)
		{
		 co1 = input1.nextInt();
		 co2 = input2.nextInt();
		 co3 = input3.nextInt();
		 co4 = input4.nextInt();
		test.displayMineAsSpecial(co1,co2,co3,co4);
			
		}
		
		
		
		/*if (choice == 6)
		{
		 co1 = input1.nextInt();
		 co2 = input2.nextInt();
		 
		System.out.println(test.isShiftoxide(co1,co2));
			
		}/*
		
		
		
		/*if (choice == 8)
		{
		 player.processOre();
		 
		//System.out.println(test.isShiftoxide(co1,co2));
			
		}*/
		
		
		/*if (choice == 7)
		{
		 co1 = input1.nextInt();
		 co2 = input2.nextInt();
		 
		System.out.println(test.shiftOre(co1,co2));
			
		}*/
		
		
   }


	System.out.println("Congractulations your score is " + player.processOre());
	System.out.println("Thankyou for playing ");
	//Sorry I couldnt comment in time. I understand if it may be hard to read
	
 


/////////////////////Developer notes, you have been given this demo version because you are a trusted beta tester. 
//At positions
// *1 *2 and *3, you can remove the comment parameters to see that the changes do work. 
//Have fun, and happy debugging! :)

//I just realised I cant even copyright this cause its not mine :(//

     


	}
}