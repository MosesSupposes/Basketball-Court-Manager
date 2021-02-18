[@react.component]
let make = (~queue: list(Team.t)) => {
  let minWaitTime = queue->List.length->float_of_int->(x => x *. 8.5);
  let maxWaitTime = queue->List.length->float_of_int->(x => x *. 12.5);

  {j|Estimated wait time: $minWaitTime - $maxWaitTime minutes.|j};
};
