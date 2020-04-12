string f(string& s){
  string res;
  if(s[0]!='?') res.push_back(s[0]);
  else res.push_back(s[1]!='?'&&s[1]>'3'?'1':'2');

  if(s[1]!='?') res.push_back(s[1]);
  else  res.push_back(res[0]=='2'?'3':'9');
  res.push_back(':');
  res.push_back(s[3]=='?'?'5':s[3]);
  res.push_back(s[4]=='?'?'9':s[4]);  
  return res;
}