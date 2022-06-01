dirty_iris <- read.csv("https://raw.githubusercontent.com/edwindj/datacleaning/master/data/dirty_iris.csv")
View(dirty_iris)

# Complete Observations of Dirty Iris 
completeObservations <- sum(complete.cases(dirty_iris))
completeObservationsPercentage <- (completeObservations/nrow(dirty_iris))*100

paste("Complete Observations :",completeObservations)
paste("Complete Observations Percentage :",completeObservationsPercentage)


columnsNames <- names(dirty_iris)
columnsNames

missingValues <- 0
OldNA <- sum(is.na(dirty_iris))
# Setting Special Values to NA
for(column in columnsNames)
{
  inf <- is.infinite(dirty_iris[[column]])
  missingValues <- missingValues + sum(is.infinite(dirty_iris[[column]]))
  dirty_iris[inf,column] <- NA
}

for(column in columnsNames)
{
  null <- is.infinite(dirty_iris[[column]])
  missingValues <- missingValues + sum(is.null(dirty_iris[[column]]))
  dirty_iris[null,column] <- NA
}

paste("Missing Values:",missingValues)
paste("Missing Values + oldNA:",missingValues+OldNA)
paste("Current NA:",sum(is.na(dirty_iris)))

# View(na.omit(dirty_iris))
# edit rules packages
#install.packages("editrules")
library(editrules)
E<-editfile("D:/Data Mining/Practicals/rules.txt")
E
x<-violatedEdits(E,dirty_iris)
print(x)
summary(x,E)
plot(x)
#x[is.na(x)] <- TRUE
#x

# Summary
library(sqldf)
ruleSet <- "SELECT
                            \"Sepal.Width\",
                            \"Sepal.Length\",
                            \"Petal.Width\",
                            \"Petal.Length\",
                            Species
                        FROM
                            dirty_iris
                        WHERE
                            \"Sepal.Length\" > 0 AND
                            \"Sepal.Width\"  > 0 AND
                            \"Petal.Length\" > 0 AND
                            \"Petal.Width\"  > 0 AND
                            \"Petal.Length\" >= 2*\"Petal.Width\" AND
                            \"Sepal.Length\" <= 30 AND
                            \"Sepal.Length\" >= \"Petal.Length\""

clean_iris <- sqldf(ruleSet)
clean_iris
columnsNames <- names(clean_iris)
columnsNames

for(column in columnsNames)
{
  cat(column,"\n")
  cat(rep(c("-"),20),"\n")
  if(is.numeric(clean_iris[[column]]))
  { 
    cat("Mean : ",mean(clean_iris[[column]],na.rm = TRUE),"\n")
    cat("Median : ",median(clean_iris[[column]],na.rm = TRUE),"\n")
    cat("Variance : ",var(clean_iris[[column]],na.rm = TRUE),"\n")
    cat("Standard Deviation : ",sd(clean_iris[[column]],na.rm = TRUE),"\n")
    cat("Median Absolute : ",mad(clean_iris[[column]],na.rm = TRUE),"\n")
    cat("Minimum : ",min(clean_iris[[column]],na.rm = TRUE),"\n")
    cat("Maximum : ",max(clean_iris[[column]],na.rm = TRUE),"\n")
    cat("Quantile : ",quantile(clean_iris[[column]],na.rm = TRUE),"\n")
    cat("Five Number Summary : ",fivenum(clean_iris[[column]],na.rm = TRUE),"\n")
  }
  else if(is.character(clean_iris[[column]]))
  { 
    cat("Unique Values : ",unique(clean_iris[[column]]),"\n")      
  }
  cat(rep(c("-"),20),"\n\n")
}

summary(clean_iris)


# Plotting

# sCATTER PLOT
# base
versicolor <- clean_iris[clean_iris$Species == "versicolor",]
virginica <- clean_iris[clean_iris$Species == "virginica",]
setosa <- clean_iris[clean_iris$Species == "setosa",]

versicolor
plot(versicolor$Sepal.Length,versicolor$Sepal.Width,xlab = "Length",ylab="Width",main="Versicolor - Sepal")
plot(versicolor$Petal.Length,versicolor$Petal.Width,xlab = "Length",ylab="Width",main="Versicolor - Petal")

virginica
plot(virginica$Sepal.Length,virginica$Sepal.Width.xlab = "Length",ylab="Width",main="Virginica - Sepal")
plot(virginica$Petal.Length,virginica$Petal.Width,xlab = "Length",ylab="Width",main="Virginica - Petal")

setosa
plot(setosa$Sepal.Length,setosa$Sepal.Width,xlab = "Length",ylab="Width",main="Setosa - Sepal")
plot(setosa$Petal.Length,setosa$Petal.Width.xlab = "Length",ylab="Width",main="Setosa - Petal")

# box plot
boxplot.stats(setosa$Petal.Length)
boxplot(setosa$Petal.Length~setosa$Petal.Width,clean_iris)
