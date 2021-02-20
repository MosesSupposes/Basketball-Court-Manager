[@react.component]
let make = (~queue: list(Team.t), ~shouldShowWaitTime: bool) => {
  let minWaitTime = queue->List.length->float_of_int->(x => x *. 8.5);
  let maxWaitTime = queue->List.length->float_of_int->(x => x *. 12.5);
  let roundedDown = Js.Math.floor;

  <div className="wait-time">
    {shouldShowWaitTime
       ? React.string(
           "Estimated wait time: "
           ++ minWaitTime->roundedDown->string_of_int
           ++ " - "
           ++ maxWaitTime->roundedDown->string_of_int
           ++ " minutes.",
         )
       : <div />}
  </div>;
};
