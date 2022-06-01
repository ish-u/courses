# Check If the Data Set is Standardized or Not
checkStandard <- function(dataset)
{
  columnsNames <- names(dataset)
  Mean <- c()
  SD <- c()
  for(column in columnsNames)
  {
    if(is.numeric(dataset[[column]]))
    {
      Mean[column]<- mean(dataset[[column]],na.rm = TRUE)
      SD[column]<- sd(dataset[[column]],na.rm = TRUE)
    }
  }
  checkMeanSD <- data.frame(
    "Mean" = Mean,
    "SD" = SD
  )
  checkMeanSD
  return(checkMeanSD)
}

# WINE DATASET
wine<- read.csv("https://archive.ics.uci.edu/ml/machine-learning-databases/wine/wine.data",header = FALSE)
columnsNames <- c('Type', 'Alcohol', 'Malic', 'Ash', 
                  'Alcalinity', 'Magnesium', 'Phenols', 
                  'Flavanoids', 'Nonflavanoids',
                  'Proanthocyanins', 'Color', 'Hue', 
                  'Dilution', 'Proline')
colnames(wine) <- columnsNames
View(wine)

wineMeanSD <- checkStandard(subset(wine,select = -c(Type)))
wineMeanSD

# Standardizing the Variables
wineMean <- wineMeanSD$Mean
names(wineMean) <- columnsNames[-1]
wineSD <- wineMeanSD$SD
names(wineSD) <- columnsNames[-1]
for(column in columnsNames)
{
  if(is.numeric(wine[[column]]) && column != "Type")
  {
    wine[[column]] <- (wine[[column]] - wineMean[column])/wineSD[column]
  }
}
checkStandard(subset(wine,select = -c(Type)))


# IRIS Data Set
data("iris", package = "datasets")
View(iris)

columnsNames <- names(iris)
irisMeanSD <- checkStandard(iris)

# Standardizing the Variables
irisMean <- irisMeanSD$Mean
names(irisMean) <- columnsNames[-5]
irisSD <- irisMeanSD$SD
names(irisSD) <- columnsNames[-5]
for(column in columnsNames)
{
  if(is.numeric(iris[[column]]))
  {
    iris[[column]] <- (iris[[column]] - irisMean[column])/irisSD[column]
  }
}

irisMeanSD <- checkStandard(iris)
irisMeanSD
