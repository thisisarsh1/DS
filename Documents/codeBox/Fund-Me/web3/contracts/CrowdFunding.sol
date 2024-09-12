// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.9;

contract CrowdFunding {
    struct Campaign {
        address owner;
        string title;  
        string description;
        uint target;
        uint deadline;
        uint amountcollected;
        string image;
        address[]donators; 
        uint[]donations;
    }   
    mapping(uint => Campaign)public campaigns;
    uint256 public numberofCampaigns=0;
    function createCampaign(address _owner,string memory _title, string memory _description, uint _target, uint _deadline, string memory _image) public returns (uint256) {
        Campaign storage newCampaign = campaigns[numberofCampaigns];
        require(newCampaign.deadline<block.timestamp,"Deadline should be in the future");
        newCampaign.owner = _owner;
        newCampaign.title = _title;
        newCampaign.description = _description;
        newCampaign.target = _target;
        newCampaign.deadline = _deadline;
        newCampaign.image = _image;
        numberofCampaigns++;
        return numberofCampaigns-1;
    
    }
    function donateToCampaign(uint _campaignId) public payable{
        uint256 amountcollected = msg.value;
        Campaign storage selectedCampaign = campaigns[_campaignId];
        selectedCampaign.donators.push(msg.sender);
        selectedCampaign.donations.push(amountcollected);
        (bool sent, ) = payable(selectedCampaign.owner).call{value:amountcollected}("");
        if (sent){
            selectedCampaign.amountcollected = selectedCampaign.amountcollected+amountcollected;
        }

    }
    function getDonators(uint _campaignId) public view returns(address[] memory,uint256[] memory){
        return(campaigns[_campaignId].donators,campaigns[_campaignId].donations);
    }
    function getCampaign() public view returns(Campaign[] memory){
       Campaign[] memory allcampaign = new Campaign[](numberofCampaigns);
       for(uint i=0;i<numberofCampaigns;i++){
        Campaign storage item = campaigns[i];
           allcampaign[i] = item;
       }
       return allcampaign;
    }
}
