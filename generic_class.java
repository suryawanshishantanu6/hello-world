import java.util.Scanner;
public class generic_class<T>
{
	private T t1;
	
	public T display(T t1)
	{
	    return t1;	
	}	

		
	public static void main(String args[])
     	{
	
	Scanner Scan=new Scanner(System.in);
	
	try
	{	
		generic_class<String>s1=new generic_class<>();
		generic_class<Integer>s2=new generic_class<>();
	
		System.out.print("\n    Enter your Name: ");
		String str=Scan.nextLine();
	
	
		System.out.print("\n    Enter your Age: ");
		int n=Scan.nextInt();
		
	

		System.out.println("\n    Name: "+s1.display(str));
		

		System.out.println("\n    Age: "+s2.display(n));
		
	}
	
catch(Exception e)
{

System.out.println("\n    Exception Occured:"+e)
System.out.println("\n    Enter Integer Value For Age!!");
	
}

}

}	
		
