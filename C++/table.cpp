int main(){
    
    
    int num;
    int tab = 1;
    cout<<"Enter The Number Whose Table You Want "<<endl;
    cin>>num;
    
    for(int i = 1; i <= 10; i++){
        tab = num*i;
        cout<<num<<" * "<<i<<" = "<<tab<<endl;
        
        
    }
}