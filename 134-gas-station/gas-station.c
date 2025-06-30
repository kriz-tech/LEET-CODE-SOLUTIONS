int canCompleteCircuit(int* gas, int gs, int* cost, int cs) {
    int total_gas = 0, total_cost = 0;

    for(int i = 0; i < gs; i++)
    {
        total_gas += gas[i];
        total_cost += cost[i];
    }
    if(total_gas < total_cost) return -1;
    int res = 0, gas_gain = 0;
    for(int i = 0; i < gs; i++)
    {
        gas_gain += gas[i] - cost[i];
        if(gas_gain < 0)
        {
            res = i + 1;
            gas_gain = 0;
        }
    }
    return total_gas >= 0 ? res : -1;
}