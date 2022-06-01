# Naive Bayes
library("klaR")
library(caret)
library(ggplot2)
library(reshape2)

# Iris Data Set
data("iris", package = "datasets")
str(iris)
summary(iris)


correlation <- cor(iris[sapply(iris, is.numeric)])
iris_melt <- melt(correlation)
ggplot(iris_melt, aes(x = Var1,
                  y = Var2,
                  fill = value))+geom_tile()



# TRAIN - 75 TEST 25
# Splitting the Data
trainIndex <- createDataPartition(iris$Species,p=0.75,list = FALSE)
# Train Set
trainSet <- iris[trainIndex,]
# Test Set
testSet <- iris[-trainIndex,]
set.seed(120)

nbClassifierHO = train(Species~.,trainSet,
                       method = 'nb',
                       trControl=trainControl(method='none',))
nbClassifierHO



# NAIVE BAYES CLASSIFIER
nbClassifierCV = train(Species~.,iris,
                       method = 'nb',
                       preProcess = c("center", "scale"),
                       trControl=trainControl(method='cv',number = 10))
nbClassifierCV
nbClassifierCV$finalModel

predictions <- predict(nbClassifierCV, testSet)
predictions
confusionMatrix(predictions, testSet$Species)

# KNN CLASSIFIER
knnClassifierCV <- train(Species~., trainSet,
                         method = "knn",
                         preProcess = c("center", "scale"),
                         trControl = trainControl(method = "cv", number = 10))


knnClassifierCV
plot(knnClassifierCV)
ggplot(knnClassifierCV)

predictions <- predict(knnClassifierCV, testSet)
predictions
confusionMatrix(predictions, testSet$Species)

# DECISION TREE
dtClassifierCV <- train(Species~., trainSet,
                        method = "J48",
                        preProcess = c("center", "scale"),
                        trControl = trainControl(method = "cv", number = 10))


dtClassifierCV
dtClassifierCV$finalModel

predictions <- predict(dtClassifierCV, testSet)
confusionMatrix(predictions, testSet$Species)




library("caret")
# install.packages("caret")
library("klaR")

data("iris")

# Partition data into Train (80%) and Test (20%) sets
trainIndex <- createDataPartition(iris$Species, p=0.80, list=FALSE)
trainIndex

irisTrain <- iris[ trainIndex,]
irisTrain

irisTest  <- iris[-trainIndex,]
irisTest

# Train model using the Train partition
set.seed(101)
nbModel = train(Species ~ .,
                irisTrain,
                method = 'nb',
                trControl=trainControl(method='none'))

nbModel$finalModel

# Predict using the Test partition
predictions <- predict(nbModel, irisTest)
predictions

confusionMatrix(predictions, irisTest$Species)


