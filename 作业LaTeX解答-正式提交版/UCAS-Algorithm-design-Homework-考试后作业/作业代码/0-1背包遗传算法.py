import numpy as np
import matplotlib.pyplot as plt
 
 
#初始化种群,popsize代表种群个数，n代表基因长度，
def init(popsize,n):
    population=[]
    for i in range(popsize):
        pop=''
        for j in range(n):
 
            pop=pop+str(np.random.randint(0,2))
        population.append(pop)
    return population
#计算种群中每个个体此时所代表的解的重量和效益
def computeFitness(population,weight,profit):
    total_weight = []
    total_profit = []
    for pop in population:
        weight_temp = 0
        profit_temp = 0
        for index in range(len(pop)):
            if pop[index] == '1':
                weight_temp += int(weight[index])
                profit_temp += int(profit[index])
        total_weight.append(weight_temp)
        total_profit.append(profit_temp)
    return  total_weight,total_profit
 
def computesingle(single,profit):
    profit_temp = 0
    for index in range(len(single)):
        if single[index] == '1':
            profit_temp += int(profit[index])
    return profit_temp
 
#筛选符合条件的
def select(population,weight_limit,total_weight,total_profit):
    w_temp = []
    p_temp = []
    pop_temp = []
    for weight in total_weight:
        out = total_weight.index(weight)
        if weight <= weight_limit:
            w_temp.append(total_weight[out])
            p_temp.append(total_profit[out])
            pop_temp.append(population[out])
    return pop_temp,w_temp,p_temp
 
 
def roulettewheel(s_pop,total_profit):
 
    p =[0]
    temp = 0
 
    sum_profit = sum(total_profit)
    for i in range(len(total_profit)):
 
        unit = total_profit[i]/sum_profit
        p.append(temp+unit)
        temp += unit
    new_population = []
    i0 = 0
    while i0 < popsize:
        select_p = np.random.uniform()
        for i in range(len(s_pop)):
 
            if select_p > p[i] and select_p <= p[i+1]:
                new_population.append(s_pop[i])
        i0 += 1
 
        # if select_p < p[0]:
        #     new_population.append(s_pop[0])
        #     i += 1
        # elif p[1] <= select_p < p[2]:
        #     new_population.append(s_pop[1])
        #     i += 1
        # for index  in range(3,len(s_pop)):
        #     if p[index - 1] < select_p <= p[index]:
        #         new_population.append(s_pop[index])
        #         i += 1
        #     break
    # print(len(new_population))
    return new_population
def ga_cross(new_population,total_profit,pcross):#随机交配
 
    new = []
 
    while len(new) < popsize:
        mother_index = np.random.randint(0, len(new_population))
        father_index = np.random.randint(0, len(new_population))
        threshold = np.random.randint(0, n)
        if (np.random.uniform() < pcross):
            temp11 = new_population[father_index][:threshold]
            temp12 = new_population[father_index][threshold:]
            temp21 = new_population[mother_index][threshold:]
            temp22 = new_population[mother_index][:threshold]
            child1 = temp11 + temp21
            child2 = temp12 + temp22
            # new.append(child1)
            # new.append(child2)
            pro1 = computesingle(child1, profit)
            pro2 = computesingle(child2, profit)
            if pro1 > total_profit[mother_index] and pro1 > total_profit[father_index]:
                new.append(child1)
            else:
                if total_profit[mother_index] > total_profit[father_index]:
                    new.append(new_population[mother_index])
                else:
                    new.append(new_population[father_index])
            if pro2 > total_profit[mother_index] and pro1 > total_profit[mother_index]:
                new.append(child2)
            else:
                if total_profit[mother_index] > total_profit[father_index]:
                    new.append(new_population[mother_index])
                else:
                    new.append(new_population[father_index])
    return new
 
def mutation(new,pm):
    temp =[]
    for pop in new:
        p = np.random.uniform()
        if p < pm:
            point = np.random.randint(0, len(new[0]))
            pop = list(pop)
 
            if pop[point] == '0':
                pop[point] = '1'
            elif pop[point] == '1':
                pop[point] = '0'
            pop = ''.join(pop)
            temp.append(pop)
        else:
            temp.append(pop)
    return temp
 
 
def plot():
    x= range(iters)
 
    plt.plot(x,ylable)
    plt.show()
 
if __name__ == "__main__":
    weight = [95,75,23,73,50,22,6,57,89,98]
 
    profit = [89,59,19,43,100,72,44,16,7,64]
 
    n = len(profit)
    weight_limit = 300
    pm = 0.05
    pc = 0.8
    popsize = 30
    iters = 500
    population = init(popsize, n)
    ylable = []
    iter = 0
    best_pop = []
    best_p = []
    best_w = []
    while iter < iters:
        print(f'第{iter}代')
        print("初始为",population)
        w, p = computeFitness(population, weight, profit)
        print('weight:',w,'profit:',p)
        print(w)
        print(p)
        s_pop, s_w, s_p = select(population, weight_limit, w, p)
 
        best_index = s_p.index(max(s_p))
        ylable.append(max(s_p))
        best_pop.append(s_pop[best_index])
        best_p.append(s_p[best_index])
        best_w.append(s_w[best_index])
        print(s_pop[best_index])
        print(s_p[best_index])
        print(s_w[best_index])
        print(f'筛选后的种群{s_pop},长度{len(s_pop)},筛选后的weight{s_w},筛选后的profit{s_p}')
        new_pop = roulettewheel(s_pop, s_p)
        w,p1 = computeFitness(new_pop, weight, profit)
        print(f'轮盘赌选择后{new_pop},{len(new_pop)}')
        new_pop1 = ga_cross(new_pop, p1, pc)
        print(f'交叉后{len(new_pop1)}')
        population = mutation(new_pop1, pm)
        print(population)
        print(f'第{iter}迭代结果为{max(s_p)}')
        iter += 1
        #print(len(population1))
    best_i = best_p.index(max(best_p))
    plot()