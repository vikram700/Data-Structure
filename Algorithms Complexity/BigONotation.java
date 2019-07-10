import java.util.Arrays;


public class BigONotation{
	private int[] theArray;
    private int arraySize = 0;
    private int itemsInArray = 0;
    static  long startTime, endTime;
    
    public static void main(String[] args){
    	// O(1) time complexity testing
        BigONotation testAlgo1 = new BigONotation(10);
        testAlgo1.generateRandomArray();
        testAlgo1.printTheArray();
        testAlgo1.addItemToArray(20);
        testAlgo1.printTheArray();
        
        System.out.println(Arrays.toString(testAlgo1.theArray));

        // O(N) time complexity testing
        // Here Linear search algo is going to be execute
        BigONotation testAlgo2 = new BigONotation(10000);
        testAlgo2.generateRandomArray();
        testAlgo2.linearSearchForValue(20);
        //testAlgo2.printTheArray();

        BigONotation testAlgo3 = new BigONotation(20000);
        testAlgo3.generateRandomArray();
        testAlgo3.linearSearchForValue(20);
        //testAlgo3.printTheArray();

       
       // O(N^2) time complexity testing
        BigONotation testAlgo4 = new BigONotation(10000);
        testAlgo4.generateRandomArray();
        testAlgo4.bubbleSort();
      //  testAlgo4.printTheArray();

        BigONotation testAlgo5 = new BigONotation(20000);
        testAlgo5.generateRandomArray();
        testAlgo5.bubbleSort();
      //testAlgo5.printTheArray();
        

        // O(logN) time Complexity
        BigONotation testAlgo6 = new BigONotation(10000);
        testAlgo6.generateRandomArray();
        testAlgo6.binarySearch(20);

        BigONotation testAlgo7 = new BigONotation(100000);
        testAlgo7.generateRandomArray();
        testAlgo7.binarySearch(1000);

        

        // O(NlogN) time complexity for sorting the array using the quickSort
        startTime = System.currentTimeMillis();
        BigONotation testAlgo8 = new BigONotation(20);
        testAlgo8.generateRandomArray();
        System.out.println("array before sorting is look like as : ");
        System.out.println(Arrays.toString(testAlgo8.theArray));

        testAlgo8.quickSort(0, testAlgo8.arraySize - 1);

        endTime = System.currentTimeMillis();

        System.out.println("So the total time taken for sorting the array using the quickSort is : " + (endTime - startTime));
        System.out.println("array after sorting look like as : ");
        System.out.println(Arrays.toString(testAlgo8.theArray));
    }
    
    public void printTheArray(){
    	System.out.println("Here we are going to print our array : ");
    	System.out.println("=======================================");
    	for(int i = 0;  i < arraySize; i++){
    		System.out.print(theArray[i]+ " ");

    	}
    	System.out.println();
    	System.out.println("=========================================");
    }


    // O(1) simply add item into the array
    public void addItemToArray(int item){
    	theArray[itemsInArray++] = item;
    }

    // O(N) LinearSearchForValue

    public void linearSearchForValue(int value){
    	boolean valueInArray = false;

    	startTime = System.currentTimeMillis();
    	for(int i=0;i<arraySize;i++){
    		if(theArray[i] == value){
    			valueInArray = true;
    		}
    	}

    	System.out.println("Value Found : " + valueInArray);

    	endTime = System.currentTimeMillis();

    	System.out.println("Linear Search Time Taken : "  + (endTime - startTime ));
    }
    

    // O(N^2) Bubble sort 

    public void bubbleSort(){
    	startTime = System.currentTimeMillis();

    	for(int i=0;i<arraySize;i++){
    		for(int j = 0;j < arraySize - i - 1; j++){
    			if(theArray[j] > theArray[j+1]){
    				swapValues(j, j+1);
    			}
    		}
    	}

    	endTime = System.currentTimeMillis();
    	System.out.println("Time taken by the bubble sort is : " + (endTime - startTime));
    } 

   // O(log n) in this step we will going to implement binary search algo
    public void binarySearch(int value){
    	startTime = System.currentTimeMillis();
        
        int timesThrough = 0;
    	int lowIndex = 0;
    	int highIndex = arraySize - 1;
    	while(lowIndex <= highIndex){
    		int middleIndex = (lowIndex + highIndex) / 2;
    		if(theArray[middleIndex] < value){
    			lowIndex = middleIndex + 1;
    		}
    		else if( theArray[middleIndex] > value){
    			highIndex = middleIndex - 1;
    		}
    		else{
    			System.out.println("the given value " + value + " is found at position " + middleIndex);
    			break;
    		}
    		timesThrough++;
    	}

    	endTime = System.currentTimeMillis();
        
        System.out.println("the total time taken by binary search is : " + (endTime - startTime));
        System.out.println("no of times : " + timesThrough);
    }

   // O(nlogn)  here we will just implement quick sort algo

    public void quickSort(int left, int right){
         if(left >=  right) return;
         else{
         	int pivot = theArray[right];
         	int position = partition(left, right, pivot);
         	quickSort(left, position - 1);
         	quickSort(position + 1, right);
         }
    }

    public int partition(int left, int right, int pivot){
    	   int leftPointer = left;
    	   int rightPointer = right;

    	   while(true){
    	   	    while(leftPointer < right){
    	   	    	if(theArray[leftPointer] > pivot) break;
    	   	    	leftPointer++;
    	   	    }

    	   	    while(rightPointer > left){
    	   	    	if(theArray[rightPointer] < pivot) break;
    	   	    	--rightPointer;
    	   	    }

    	   	    if(leftPointer >= rightPointer){
    	   	    	break;
    	   	    }else{
    	   	    	swapValues(leftPointer, rightPointer);
    	   	    }

    	   	}
    	   swapValues(leftPointer, right);
    	   return leftPointer;
    }


    BigONotation(int size){
    	arraySize = size;
    	theArray = new int[size];
    }

    public void generateRandomArray(){
    	for(int i=0;i<arraySize;i++){
    		theArray[i] = (int)(Math.random() * 1000) + 10;
    	}
    	itemsInArray = arraySize - 1;
    }
 
    public void swapValues(int i, int j){
    	int temp = theArray[i];
    	 theArray[i] = theArray[j];
    	 theArray[j] = temp;
    }
}