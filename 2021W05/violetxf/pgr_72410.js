/*
    신규 아이디 추천
    https://programmers.co.kr/learn/courses/30/lessons/72410
*/
function solution(new_id) {
    new_id=new_id.toLowerCase();
    new_id=new_id.replace(/[^a-z0-9\-_.]/g,"");
    new_id=new_id.replace(/\.{2,}/g,".");
    new_id=new_id.replace(/(^\.|\.$)/g,"");
    if(new_id=="")new_id="a";
    if(new_id.length>=16)new_id=new_id.substr(0,15);
    new_id=new_id.replace(/\.$/g,"");
    if(new_id.length==1)new_id+=new_id.repeat(2);
    if(new_id.length==2)new_id+=new_id[1];
    return new_id;
}