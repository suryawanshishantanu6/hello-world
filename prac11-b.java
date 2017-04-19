import java.util.Scanner;

public class shell_sort
{
	void shellSort(int a[],int n)
	{
		int gap,i,j,temp;
		for(gap=n/2;gap>0;gap=gap/2)
		{
			for(i=gap;i<n;i++)
			{
				temp=a[i];
				for(j=i;j>=gap && temp<a[j-gap];j=j-gap)
				{
					a[j]=a[j-gap];
				}
				a[j]=temp;
			}
		}
	}
	public static void main(String args[])
	{
		Scanner s=new Scanner(System.in);
		int a[],n,i;
		shell_sort obj=new shell_sort();
		System.out.print("Enter the total number of elements: ");
		n=s.nextInt();
		a=new int[n];
		for(i=0;i<n;i++)
		{
			System.out.print("Enter element "+(i+1)+": ");
			a[i]=s.nextInt();
		}
		
		obj.shellSort(a,n);
		
		System.out.println("Sorted Array is:");
		for(i=0;i<n;i++)
			System.out.print("\t"+a[i]);
		System.out.println();
	}
}

/*OUTPUT:
Enter the total number of elements: 5
Enter element 1: 5
Enter element 2: 4
Enter element 3: 3
Enter element 4: 2
Enter element 5: 1

Sorted Array is:
	1	2	3	4	5
*/		
