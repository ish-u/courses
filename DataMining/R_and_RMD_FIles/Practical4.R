library(arules)
library(arulesViz)

# Groceries Data Set
data("Groceries")
summary(Groceries)
inspect(Groceries[1:5])

rules.all <- apriori(Groceries, parameter = list(supp = 0.060, conf = 0.070,target="rules"))
inspect(head(rules.all))

rules.all$

plot(rules.all)
plot(rules.all, method="grouped")

rulesLHS <- apriori (data=Groceries, parameter=list (supp=0.001,conf = 0.08), appearance = list (lhs="canned beer",rhs="diapers"), control = list (verbose=F))
#rulesLHS <- apriori(Groceries, control = list(verbose=F),parameter = list(minlen=3, supp=0.002, conf=0.7),appearance = list(lhs=c("canned beer"),default="none"))
quality(rulesLHS) <- round(quality(rulesLHS), digits=4)
rulesLHS.sorted <- sort(rulesLHS, by="lift")
inspect(head(rulesLHS.sorted))



# Online Retail Data Set
# https://www.datacamp.com/community/tutorials/market-basket-analysis-r
library(readxl)
library(plyr)
library(dplyr)

online <- read_excel("D:\\Data Mining\\Practicals\\Online Retail.xlsx")
online <- online[complete.cases(online), ]
View(online)

online %>% mutate(Description = as.factor(Description))
online %>% mutate(Country = as.factor(Country))
online$Date <- as.Date(online$InvoiceDate)
TransTime<- format(online$InvoiceDate,"%H:%M:%S")
InvoiceNo <- as.numeric(as.character(online$InvoiceNo))
cbind(online,TransTime)
cbind(online,InvoiceNo)
glimpse(online)


transactionData <- ddply(online,c("InvoiceNo","Date"),
                         function(df1)paste(df1$Description,
                                            collapse = ","))
transactionData

transactionData$InvoiceNo <- NULL
transactionData$Date <- NULL
colnames(transactionData) <- c("items")


write.csv(transactionData,"D:\\Data Mining\\Practicals\\Online Retail.csv", quote = FALSE, row.names = FALSE)
tr <- read.transactions('D:\\Data Mining\\Practicals\\Online Retail.csv', format = 'basket', sep=',')
summary(tr)
tr

# Create an item frequency plot for the top 20 items
if (!require("RColorBrewer")) {
  # install color package of R
  install.packages("RColorBrewer")
  #include library RColorBrewer
  library(RColorBrewer)
}
itemFrequencyPlot(tr,topN=20,type="absolute",col=brewer.pal(8,'Pastel2'), main="Absolute Item Frequency Plot")


association.rules <- apriori(tr, parameter = list(supp=0.001, conf=0.75,maxlen=10))
summary(association.rules)

inspect(head(association.rules))

plot(association.rules[quality(association.rules)$confidence>0.4])
plot(association.rules[quality(association.rules)$confidence>0.4],method = "grouped")
plot(association.rules[quality(association.rules)$confidence>0.4],method = "two-key plot")
