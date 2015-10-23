

unsigned n=xz.size();

vector< vector<double> > t;

for (unsigned i=0;i<n;++i)
{
	vector<double> row;
	row.push_back(z[i]);
t.push_back(row);
}


n=t.size();

for (unsigned i=0;i<n-1;++i){

	if(i%2==0){
	t[i].push_back(dyp[2*i]);
}
else{
	double d=(t[i][0] - t[i+1][0]/((xz[i]-xz[i+1]);
t[i].push_back(d);


}



}

for (unsigned i=0;i<n;++i){
	for (unsigned j=0;j<n-i;++j){
	double d=(t[j][i-1]-t[j+1][i-1])
	/(xz[j]-xz[i+j]);
	t[j].push_back(d);

}


}
