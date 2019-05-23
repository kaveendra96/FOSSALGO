function bubble_Sort(a)
{
    let swapp;
    let n = a.length-1;
    let x=a;
    do {
        swapp = false;
        for (var i=0; i < n; i++)
        {
            if (x[i] < x[i+1])
            {
               var temp = x[i];
               x[i] = x[i+1];
               x[i+1] = temp;
               swapp = true;
            }
        }
        n--;
    } while (swapp);
 return x; 
}

console.log(bubble_Sort([2,43,432,45,324,32,65,76,434,434,5676,3]));
