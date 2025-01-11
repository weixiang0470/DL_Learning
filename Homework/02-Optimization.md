# Fails because...
1. Gradient is close to zero -- Critical point
    - Local minima
        - no way to go
    - Saddle point
        - Where gradient == 0 but not local maxima or minima
        - able to escape
2. Batch size
3. Momentum
# How to know is local m or saddle point
- Tayler Series Approximation

![](img/02/tayler1.png)

![](img/02/hessian.png)
- When the gradient == 0, we can use hessian to identify whether we stuck at local minima or saddle point

![](img/02/hessian2.png)
- If eigen values of H are
    1. All positive -> Local minima
    2. All negative -> Local maxima
    3. Have +Ve and -Ve -> Saddle point

## Example

![hessian-ex1](img/02/hessian-ex1.png)
- Getting hessian matrix at critical point ($w_1=0,w_2=0$)
    - Eigen values are 2 and -2 -> is a saddle point

![hessian-ex2](img/02/hessian-ex2.png)
- Hessian can tell us which direction to update inorder to escape saddle point
    - If $eigenvalue of u < 0 \to \theta = \theta' + u$ will decrease L 

![hessian-ex3](img/02/hessian-ex3.png)
- But this method is rarely use in practice, because need too much calculation

# Batch
- Large batch (full batch)
    - Need to see all training data then update L
    - Update slow but powerful, without GPU
- Small batch (batch size = 1)
    - Update L for 1 training data
    - Update fast but noisy, without GPU

![svl](img/02/batch/svl.png)
- Because of parallel computing large batch size may not necessary require longer time
- But GPU have limitation

![svl1](img/02/batch/svl1.png)
- Samll batch size require more update time in a epoch
- So large batch size may train faster than small batch 

![svl2](img/02/batch/svl2.png)
- But small batch size always reach higher accuracy than large batch size

![svl3](img/02/batch/svl3.png)
- Possible reason is small batch because the update is noisy, it make training escape critical point with different $L^i$

![svl4](img/02/batch/svl4.png)
- A study conclude that small batch size always perform better on testing set

![svl5](img/02/batch/svl5.png)
- Possible reason that small batch size having better performance on testing set is **small batch size** may reach **flat minima** while **large batch size** may reach **sharp minima**

![svl6](img/02/batch/svl6.png)
- Simple conclusion about small batch and large batch size

# Momentum

![gm1](img/02/momentum/gm1.png)
- With momentum we not only consider current gradient, but also the previous gradient(step)

![gm2](img/02/momentum/gm2.png)
- Math and facts about momentum

# Learning rate
- When loss is stucking(no more decreasing), not necessary means gradient = 0, it can be moving between +ve and -ve
- Learning rate cannot be **one-size-fits-all**
    - **Small** at direction with **large gradient** 
    - **Large** with direction with **small gradient**

![lr0](img/02/LR/lr0.png)
- Use another hyperparameter to control the learning rate in specific dimention called $\sigma_i^t$
    - t: iteration
    - i: specific dimention
## Adagrad

![lr1](img/02/LR/lr1.png)
- Using Root mean square to calculate the next $\sigma$

![lr2](img/02/LR/lr2.png)

## RMSProp

![lr3](img/02/LR/lr3.png)
- Use $\alpha$ to control the importance of current gradient
    - Small $\alpha \to$ current gradient is more important 
    - Large $\alpha \to$ previous gradient are more important

![lr4](img/02/LR/lr4.png)

## Adam

![lr5](img/02/LR/lr5.png)

## Other problem

![lr6](img/02/LR/lr6.png)
- Even the model can reach to minimum loss in the end, but still have some oscillation after long time of flat gradient
    - Accumulation many of small gradient will make $\sigma$ become very small, this will give larger in $\eta \over \sigma^t_i$

![lr7](img/02/LR/lr7.png)
- So we can decrease the learning rate as time goes to get to the minimum faster and smooth

![lr8](img/02/LR/lr8.png)
- **Residual Network**
- **BERT**
- **Transformer**
- Use in many famous network, but no well explain in the paper
- $\sigma$ need many data to be accurate, so when starting we need to give $\sigma$ some time to collect data
    - starting with small learning rate $(\eta)$ then increase it

![lr9](img/02/LR/lr9.png)
- Momentum consider the direction
- $\sigma$ consider only magnitude (root mean square)