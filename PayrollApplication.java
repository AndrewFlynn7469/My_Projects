import java.util.Scanner;

public class PayrollApplication {

    public static void main(String[] args) {
        Payroll a = new Payroll();
        Scanner kb = new Scanner(System.in);
        
        a.setAll();
        System.out.println(a);
        
        System.out.println("Do you want to start the test, Y/N or y/n?");
        String str = kb.nextLine();

        while((str.toUpperCase()).charAt(0)=='Y'){
            System.out.println("1: Dispaly the whole table.");
            System.out.println("2: Reset the whole table.");
            System.out.println("3: Dispaly the record of a person with index.");
            System.out.println("4: Dispaly the record of a person with his/her ID.");
            System.out.println("5: Update any individual record.");
            System.out.println("other number: quit!");
   
            int event = kb.nextInt();
            int index, id;
   
            switch(event){
            
            case 1: 
                System.out.println(a);
                break;
            case 2:
                a.setAll();
                break;
            case 3:
               System.out.println("Input Index please:");
               index = kb.nextInt();
           
               
               System.out.println("Hours:"+a.getHours(index));
               System.out.println("PayRate:"+a.getPayRate(index));
               System.out.println("Wages:"+a.getWages(index));               
               break;
            case 4:
               System.out.println("Input employee ID please:");
               id = kb.nextInt();
               
               index=a.getIndex(id);
                                                            
               if(index!=-1){
                  System.out.println("Hours:"+a.getHours(index));
                  System.out.println("PayRate:"+a.getPayRate(index));
                  System.out.println("Wages:"+a.getWages(index));               
               }
               else System.out.println("Either not found or out of range.");
               
               break;
            case 5:
               index=-1;
               
               System.out.println("1. Update hours with index.");
               System.out.println("2. Update hours with employee ID.");
               System.out.println("3. Update payRate with index.");
               System.out.println("4. Update payRate with employee ID.");
               System.out.println("Other number. Back to Main menu.");
               event = kb.nextInt();
               
               while(event>=1&&event <=4){
               if(event==1||event ==3){
                  System.out.println("Input Index please:");
                  index = kb.nextInt();
               }
               else if (event ==2||event==4){
                  System.out.println("Input ID please:");
                  id = kb.nextInt();
                  index=a.getIndex(id);
               }
               else index = -1;
                              
               if(index!=-1){
                  if(event==1)a.setHours(index);
                  else
                  a.setPayRate(index);
                  a.setWages(index);
                  System.out.println("Wages:"+a.getWages(index));
                  System.out.println();               
               }
               else System.out.println("Either not found or out of range!");

               System.out.println("1. Update hours with index.");
               System.out.println("2. Update hours with employee ID.");
               System.out.println("3. Update payRate with index.");
               System.out.println("4. Update payRate with employee ID.");
               System.out.println("Other number. Back to Main menu.");
               event = kb.nextInt();
              }
            }
        if(event < 1 || event >5 ) str = "N";
        else{
            System.out.println("Do you want to continue the test, Y/N or y/n?");
            kb.nextLine(); //consume the print-out information for the below reading
            str = kb.nextLine();
        }
      }
   }
}