@react.component
let make = (~queue: list<Team.t>, ~shouldShowWaitTime: bool) => {
  let minWaitTime = queue->List.length->float_of_int->(x => x *. 8.5 -. 8.5)
  let maxWaitTime = queue->List.length->float_of_int->(x => x *. 12.5 -. 12.5)
  let roundedDown = Js.Math.floor

  shouldShowWaitTime
    ? <div className="wait-time">
        {List.length(queue) > 1
          ? React.string(
              "Estimated wait time: " ++
              (minWaitTime->roundedDown->string_of_int ++
              (" - " ++ (maxWaitTime->roundedDown->string_of_int ++ " minutes."))),
            )
          : "Estimated wait time: 0 min"->React.string}
      </div>
    : <div />
}
