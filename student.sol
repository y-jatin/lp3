pragma solidity ^0.8.0;

contract studentData{
    struct student{
        string name;
        uint age;
    }

    student[] public studentArray;

    function addStudentData(string memory name, uint age) public{
        for(uint i = 0; i < studentArray.length; i++){
            if (studentArray[i].age == age){
                revert("Roll already exists");
            }
        }
        studentArray.push(student(name,age));
    }

    function displayAllData() public view returns(student[] memory){
        return studentArray;
    }

    function getStudentLength() public view returns(uint){
        return studentArray.length;
    }

    function getData(uint index) public view returns(student memory){
        require(index < studentArray.length, "Index out of bound");
        return studentArray[index];
    }

    fallback() external payable{

    }

    receive() external payable{
        
    }
}