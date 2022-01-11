DROP TABLE IF EXISTS all_questions2; 
CREATE TABLE all_questions2(
	QuestionID INT
);

ALTER TABLE all_questions2
ADD COLUMN Level1 VARCHAR(255), 
ADD COLUMN Level2 VARCHAR(255);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Sample Source',1);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Age',2);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Gender',3);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Relationship Status',4);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Household',5);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Income',6);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Investable assets',7);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Primary Income Earner Occupation',8);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Primary Income Earner Sector',9);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Pension Decisions',10);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Pension Type',11);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Knowledge',12);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Other Financial Holdings',13);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Estimated total value - ISA',14);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Estimated total value - Property',15);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Estimated total value - Cash',16);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Estimated total value - Inheritance',17);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Estimated total value - Other investments',18);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Estimated total value - Don''t know / Prefer not to answer',19);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Regularly check in media','Financial Sophistication',20);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Confident handling own finances','Financial Sophistication',21);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Knowledgeable about finances','Financial Sophistication',22);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Low Financial Sophistication','Financial Sophistication Classification',23);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Medium Financial Sophistication','Financial Sophistication Classification',24);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('High Financial Sophistication','Financial Sophistication Classification',25);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Interest level',26);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Current Value',27);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Annual Income',28);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Annual Income Value',29);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Retirement Age',30);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Plans for Retirement',31);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Secure in Retirement',32);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('During career','Taking Advice',33);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Approaching retirement','Taking Advice',34);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('At retirement','Taking Advice',35);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('During retirement','Taking Advice',36);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Advice Driver',37);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Advice First Stop',38);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Pension General Consideration',39);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Pension Most Likely Consideration',40);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Fees Importance',41);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Financial Advisor',42);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Advisor Reliance',43);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Advice Type',44);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Advisor Value',45);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('No Advisor',46);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Advisor Consideration',47);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Advisor Qualities',48);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Advice Frequency',49);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Specialist Type',50);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Combining Generations',51);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Views on Retirement',52);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Financial Security','Retirement Goals',53);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Better standard of life','Retirement Goals',54);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Maintain standard','Retirement Goals',55);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Experience new things','Retirement Goals',56);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Not be a burden on my family','Retirement Goals',57);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('More disposable income','Financial Goals',58);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Enough to live on without budget','Financial Goals',59);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Enough to last my life','Financial Goals',60);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Support younger generation','Financial Goals',61);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Leave inheritance','Financial Goals',62);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Provision','Financial Goals',63);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('A lot of interest','Pension Provision',64);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Only think about pension when sending annual statement','Pension Provision',65);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Confident pension will support retirement','Pension Provision',66);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Unaware of pension I don’t really know how much money I need to have in my pot','Pension Provision',67);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Good understanding of process','Pension Provision',68);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Take advice on legislative changes','Pension Provision',69);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Importance of flexibility','Pension Provision',70);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Pension Investment Information',71);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Lifetime Retirement - Aged 55-64 years',72);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Lifetime Retirement - Aged 65-74 years',73);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Lifetime Retirement - Aged 75-84 years',74);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Lifetime Retirement - Aged 85+ years',75);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Lifetime Retirement - Leave as a legacy (inheritance)',76);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Personal experience','Information Sources',77);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Advice from friends and family','Information Sources',78);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('People in the media such as Martin Lewis','Information Sources',79);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Other investors on social media','Information Sources',80);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('The government (e.g. Pensionwise)','Information Sources',81);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Professional financial advisers','Information Sources',82);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Information from pension product providers','Information Sources',83);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Investment Reasons',84);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Investment Prevention',85);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Age to access pension','Knowledge Confidence',86);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Accessible amount','Knowledge Confidence',87);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Tax paid on pension','Knowledge Confidence',88);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Age to Access',89);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Proportion to Access',90);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Tax to Pay',91);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('1 - Very poorly','Understanding of Changes',92);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('2','Understanding of Changes',93);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('3','Understanding of Changes',94);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('4','Understanding of Changes',95);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('5','Understanding of Changes',96);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('6','Understanding of Changes',97);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('7','Understanding of Changes',98);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('8','Understanding of Changes',99);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('9','Understanding of Changes',100);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('10 - Very well','Understanding of Changes',101);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Revised Pension System',102);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('More choice','Sentiment on Changes',103);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('More control','Sentiment on Changes',104);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Worried','Sentiment on Changes',105);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Investing Plans',106);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('More/ better information & education','Changes to Pension System',107);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Increased trust in the system','Changes to Pension System',108);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Greater transparency around fees and charges','Changes to Pension System',109);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('More/ better incentives (e.g. Tax breaks)','Changes to Pension System',110);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Information and Education Stakeholder',111);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Need Better Trust',112);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Better Incentives',113);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Planning Consideration',114);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Talk to friends and family','Planning Process',115);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Talk to my partner','Planning Process',116);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Search online','Planning Process',117);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Search recommendations','Planning Process',118);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Traditional media','Planning Process',119);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Speak to a professional advisers','Planning Process',120);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Talk to a pension provider','Planning Process',121);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Flexibility',122);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Changing Needs',123);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Changing Needs Reason',124);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Lesser Need Reason',125);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Lots of people like me invest in it','Planning Pension Factors',126);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Recommendation from friend','Planning Pension Factors',127);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Professional advice','Planning Pension Factors',128);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Make my own decisions','Planning Pension Factors',129);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('How my financial circumstances may change in the future','Planning Pension Factors',130);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('How Much to Invest',131);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Willingness to Risk',132);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Encouraging Factors',133);

INSERT INTO all_questions2 (Level1,QuestionID)
VALUES ('Discouraging Factors',134);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Later life annuity','New Ideas',135);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Online training programme','New Ideas',136);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Idiot guide','New Ideas',137);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Tripadvisor for pension','New Ideas',138);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Comparision side','New Ideas',139);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('App to access pension','New Ideas',140);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Loyalty reward','New Ideas',141);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Life plan','New Ideas',142);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Jargon buster','New Ideas',143);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Flexibility','New Ideas',144);

INSERT INTO all_questions2 (Level1,Level2,QuestionID)
VALUES ('Forum','New Ideas',145);

SELECT * FROM all_questions2;