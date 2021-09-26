// greedy approach
static bool mycmp(val &p1, val &p2 )
{
    return p1.second < p2.second;
}


int maxChainLen(struct val p[],int n)
{
//Your code here
int prev = 0;
int curr = 1;

    sort(p,p+n,mycmp);
    for(int i = 1 ;  i<n ; i++)
    {
        if(p[i].first > p[prev].second)
        {
            prev = i;
            curr++;
        }
    }
    return curr;


}
