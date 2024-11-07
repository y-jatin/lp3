// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract bank{
    mapping(address => uint) balance;

    function deposit() public payable{
        balance[msg.sender] += msg.value;
    }

    function withdraw(uint amount) public{
        require(amount <= balance[msg.sender], "Insufficient balance");
        balance[msg.sender] -= amount;
        payable(msg.sender).transfer(amount);
    }

    function checkBalance() public view returns (uint){
        return balance[msg.sender];
    } 
    /// explain me datatypes in solidity with example
}

