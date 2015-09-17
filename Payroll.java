import java.util.Scanner;
import java.util.Arrays;

public class Payroll{

Scanner kb=new Scanner (System.in);

private int[] employeeId={5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
private int []hours=new int[7];
private double [] payRate=new double[7];
private double [] wages=new double[7];

public void setAll(){
   for(int i=0;i<7;i++){
      System.out.println("Please enter pay rate for employee no. "+(i+1)+":");
      this.payRate[i]=kb.nextDouble();
      
      while(payRate[i]<6.00){
         System.out.println("Invalid wage, please try again: ");
         this.payRate[i]=kb.nextDouble();
         }
      
      System.out.println("Please enter hours for employee no. "+(i+1)+":");
      this.hours[i]=kb.nextInt();
      
      this.wages[i]=payRate[i]*hours[i];
      
      }
      toString();
}

public int getIndex(int ID){
   int index=-1;
   
   for(int i=0;i<7;i++){
      if(ID==employeeId[i])
         index=i;
   }
   
   return index;
}

public int getHours(int i){
   return hours[i];
}

public double getPayRate(int i){
   return payRate[i];
}

public double getWages(int i){
   return wages[i];
}

public void setHours(int i){
   System.out.println("Please enter hours for employee no. "+(i+1)+":");
   this.hours[i]=kb.nextInt();
}

public void setPayRate(int i){
   System.out.println("Please enter pay rate for employee no. "+(i+1)+": ");
   this.payRate[i]=kb.nextDouble();
   
   while(payRate[i]<6.00){
     System.out.println("Invalid rate, please enter another value: ");
     this.payRate[i]=kb.nextDouble();
   }
}


public void setWages(int i){
   this.wages[i]=payRate[i]*hours[i];
}

public String toString(){
   String s=(Arrays.toString(employeeId)+"\n");
   s+=(Arrays.toString(hours)+"\n");
   s+=(Arrays.toString(payRate)+"\n");
   s+=(Arrays.toString(wages)+"\n");
   return s;
   }
}